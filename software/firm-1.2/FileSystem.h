#include "pico/stdio.h"
#include "pico_hal.h"
#include "stdinit.h"
#include <string>

class FileSystem {
public:
    bool shouldSetClock=false;

    int fileWeekday=0;

    int fileToday=0;
    int fileMonth=0;
    int fileYear=0;

    int fileHour=0;
    int fileMinute=0;
    int fileZone=0;

    int dayOffSet=0;
    //const char* magicString = "3240523181807";
    
    //(13 char string)
    //dow, day, month, year, hour, minute, zone
    
    const char* magicString="nanoplanktons\0";
    //const char* magicString="3201223235833\0";

    void init() {
        // Mount the file system without formatting on failure
        if (pico_mount(false) != LFS_ERR_OK) {
            pico_mount(true);
            //printf("Error mounting FS\n");
            //exit(-1);
        }
        /*

        int file = pico_open("hello.txt", LFS_O_RDWR | LFS_O_CREAT);

        // Write the "Hello, World!" string to the file
        const char *message = "Hello, World!";
        pico_write(file, message, strlen(message));

        // Rewind the file to the beginning
        pico_rewind(file);

        // Read the content of the file into a buffer
        char buffer[64];
        pico_read(file, buffer, sizeof(buffer));

        // Close the file
        pico_close(file);

        // Unmount the file system, freeing memory
        pico_unmount();

        // Print the content of the file
        printf("File content: %s\n", buffer); 

        */
        
        int magicStringStorage = pico_open("magicStorage.txt", LFS_O_RDWR | LFS_O_CREAT);

        printf("file size %d \n",pico_size(magicStringStorage));
       
        pico_rewind(magicStringStorage);

        char magicStorageBuff[14]={0};


        printf("read result: %d \n",pico_read(magicStringStorage, magicStorageBuff, sizeof(magicStorageBuff)));
        magicStorageBuff[13]='\0';

        printf("buffer content: %s\n", magicStorageBuff); 
        printf("magic string: %s\n", magicString); 

        printf("comp result %d \n",strcmp(magicStorageBuff,magicString));
        
        //string comp returns zero when they ARE the same string
        //so this tests if they are different, aka is there a non zero difference btwn them? 
        //
        if(strcmp(magicStorageBuff,magicString)!=0)
        {
            //RESET test offsetter
            printf("not the same string \n");

            //when not the same string, write the clock, write magicString to magicStringStorage
            shouldSetClock=true;

            pico_rewind(magicStringStorage);
            pico_write(magicStringStorage, magicString, strlen(magicString));
            int pos = pico_lseek(magicStringStorage, 0, LFS_SEEK_CUR); 

            //printf("file size after write %d \n",pico_size(magicStringStorage));

            //Split the magicString into local date values
            long long magicNum = atoll(magicString);

            printf("magic string atoll p2: %lld \n",atoll(magicString));

   // Extract the digits
    fileWeekday = (int)(magicNum / 1000000000000);
    fileToday = (int)((magicNum / 10000000000) % 100);
    fileMonth = (int)((magicNum / 100000000) % 100);
    fileYear = (int)((magicNum / 1000000) % 100);
    fileHour = (int)((magicNum / 10000) % 100);
    fileMinute = (int)((magicNum / 100) % 100);
    fileZone = (int)(magicNum % 100);

    // Print the extracted digits
    printf("File Weekday: %d\n", fileWeekday);
    printf("File Today: %d\n", fileToday);
    printf("File Month: %d\n", fileMonth);
    printf("File Year: %d\n", fileYear);
    printf("File Hour: %d\n", fileHour);
    printf("File Minute: %d\n", fileMinute);
    printf("File Zone: %d\n", fileZone);

        } 
        pico_close(magicStringStorage);
        pico_unmount();


        //if(strcmp(magicStorageBuff,magicString)!=0)

        printf("end of file reading");

    }


    void offSetIncrement()
    {
        pico_mount(false);
        lfs_size_t boot_count;
        //int boot_count;
        // Open (create if doesn't exist) the boot count file
        int file = pico_open("boot_count", LFS_O_RDWR | LFS_O_CREAT);
        boot_count = 0;
        // Read previous boot count. If file was just created read will return 0 bytes
        pico_read(file, &boot_count, sizeof(boot_count));
        // Increment the count
        //
        if(boot_count < 32000)
        {
            boot_count += 1;
        }
        // Write it back after seeking to start of file
        pico_rewind(file);
        pico_write(file, &boot_count, sizeof(boot_count));
        // save the file size
        int pos = pico_lseek(file, 0, LFS_SEEK_CUR);
        // Close the file, making sure all buffered data is flushed
        pico_close(file);
        // Unmount the file system, freeing memory
        pico_unmount();

        dayOffSet=boot_count;
//        int bc = boot_count;
//        return bc;
    }
};
