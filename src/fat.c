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
struct root_directory_entry *rde;


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

    unsigned int root_sector_value = bs->num_fat_tables * bs->num_sectors_per_fat + bs->num_reserved_sectors + bs->num_hidden_sectors;
    
    
    
    sd_readblock(root_sector_value, root_sector, 1);
    rde = root_sector;

    esp_printf(putc,"root sector has been read in\n");
    esp_printf(putc, "clust is %x\n", rde->cluster);
    esp_printf(putc, "file size is is %x\n", rde->file_size);
     esp_printf(putc,"FILE NAME I HOPE\n");
    int c;
    for(c=0;b<15;c++){
        esp_printf(putc, "%c\n", rde->file_name[c]);
    }
    

    // TODO: Compute root_sector as:
    //       num_fat_tables + num_sectors_per_fat + num_reserved_sectors + num_hidden_sectors

    //fat_table=bs.num_fat_tables; //HOW DO I GET THE FAT TABLE JESUS
    // TODO: Read FAT table from the SD card into array fat_table

}

struct file fatOpen(struct file* file, char*filename){

    //return some file
}

void fatRead(){

}