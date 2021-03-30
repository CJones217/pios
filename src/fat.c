#include "fat.h"
#include "sd.h"
#include <stdint.h>
#include "rprintf.h"
#include "serial.h"
#include "clibfuncs.h"


struct boot_sector *bs;
char bootSector[512];
char fat_table[8*SECTOR_SIZE];
unsigned int root_sector;
unsigned int first_data_sector;



void fatInit(){
    sd_init();
    sd_readblock(0, bootSector, 1); // Read sector 0 from disk drive into bootSector array
    bs = bootSector; // Point boot_sector struct to the boot sector so we can read fields

    char fs_type_value[8];
    int i = 0;
    int j = 0;
    esp_printf(putc, "fs type: ");
    while(i<8){
        //esp_printf(putc,"fs type: %c\r\n", bs->fs_type[i]);
        esp_printf(putc, "%c", bs->fs_type[i]);
        if(bs->fs_type[i]!= ' '){
            fs_type_value[j] = bs->fs_type[i];
            j++;
        }
        i++;
    }
    esp_printf(putc, " \n");
    esp_printf(putc, " \n");
    // Print out some of the elements of the BIOS information block using rprintf... done

    if(bs->boot_signature == 0xaa55){
        esp_printf(putc,"boot signature is: %x\r\n", 0xaa55);
    } else{
        esp_printf(putc,"BOOT SIGNATURE IS NOT: %x\r\n", 0xaa55);
    }
    // TODO: Validate the boot signature = 0xaa55 done
    
    esp_printf(putc, " \n");
    esp_printf(putc, " \n");

    if(strcmp(fs_type_value, "FAT16")==0){
        esp_printf(putc,"file system type is FAT16\r\n");
    }else{
        esp_printf(putc,"file system type IS NOT FAT16 it is \r\n");
        int b;
        for(b=0;b<j;b++){
            esp_printf(putc,"%c", fs_type_value[b]);
        }
        esp_printf(putc,"\n");
    }
    // TODO: Validate fs_type = "FAT12" using strcmp done

    esp_printf(putc, " \n");
    esp_printf(putc, " \n");
    //esp_printf(putc,"num_fat_tables: %d\n",bs->num_fat_tables);
    //esp_printf(putc,"num_sectors_per_fat: %d\n",bs->num_sectors_per_fat);
    //esp_printf(putc,"num_reserved_sectors: %d\n",bs->num_reserved_sectors);
    //esp_printf(putc,"num_hidden_sectors: %d\n",bs->num_hidden_sectors);

    root_sector = (bs->num_fat_tables * bs->num_sectors_per_fat) + bs->num_reserved_sectors + bs->num_hidden_sectors;

    first_data_sector = bs->num_reserved_sectors + (bs->num_fat_tables * bs->num_sectors_per_fat) + ((bs->num_root_dir_entries * 32)+ (SECTOR_SIZE - 1)) / SECTOR_SIZE;
    
    
    /*sd_readblock(root_sector_value, root_sector, 8);
    rde = root_sector;

    esp_printf(putc,"root sector has been read in\n");
    esp_printf(putc, "clust is %x\n", rde->cluster);
    esp_printf(putc, "file size is is %x\n", rde->file_size);
     esp_printf(putc,"FILE NAME I HOPE\n");
    int c;
    for(c=0;c<8;c++){
        esp_printf(putc, " %c", rde->file_name[c]);
    }
    esp_printf(putc," \n");*/



    //unsigned int fat_offset = rde->cluster * 2;
    //unsigned int ent_offset = fat_offset % SECTOR_SIZE;
    //unsigned short table_value = *(unsigned short*)&fat_table[ent_offset];
    //esp_printf(putc, "table value %d\n", table_value);

    // TODO: Compute root_sector as:
    //       num_fat_tables + num_sectors_per_fat + num_reserved_sectors + num_hidden_sectors

    //fat_table=bs.num_fat_tables; //HOW DO I GET THE FAT TABLE JESUS
    // TODO: Read FAT table from the SD card into array fat_table

}

void fatOpen(struct file* file, char*filename){
    unsigned int sector_value = root_sector;
    esp_printf(putc, "sector value %d", sector_value);
    unsigned int put_in_rde[SECTOR_SIZE];
    unsigned int total_entries = bs->num_root_dir_entries;
    struct root_directory_entry *rde;
    char file_buffer[10];
    sd_readblock(root_sector, put_in_rde , 1);
    rde = put_in_rde;

    /*int c;
    for (c=0; filename[c]!="\0";c++) { //this will turn the filename into all caps for FAT
            char temp = filename[c];
            filename[c] = toupper(temp);
        }*/

    int i;
    for( i=0;i<total_entries;i++){//iterate through each root directory entry
        int j;
        for( j=0; j<NAME_SIZE;j++){
            if(rde->file_name[j]!=' '&&rde->file_name[j]!=0)
                file_buffer[j]=rde->file_name[j];
            else{
                file_buffer[j]=0;
            }
        }
        file_buffer[NAME_SIZE-1]=0;
         esp_printf(putc, "buffer: %s\n",file_buffer);
         esp_printf(putc, "file name: %s\n",rde->file_name);
        
        if(strcmp(file_buffer,filename)==0){
            file->rde = *rde;
            file->start_cluster=rde->cluster;
            esp_printf(putc, "it Worked!\n");
            break;
            
        }
        rde++;
    }


}

void fatRead(struct file* file, char* buffer[], unsigned int bytes_to_read){

    unsigned int cluster = file-> start_cluster;
    unsigned int total_sectors_per_cluster = bs->num_sectors_per_cluster;
    unsigned int data_sector = first_data_sector + ((file->rde.cluster - 2) * total_sectors_per_cluster);
    char* results = buffer;
    char cluster_buffer[SECTOR_SIZE];

    sd_readblock(data_sector,cluster_buffer,1);

    //esp_printf(putc, "file name: %s\n", file->rde.file_name);
    
    int i;
    for(int i=0;i<bytes_to_read;i++){
        *results++ = cluster_buffer[i];
    }


    
}