//
//  main.c
//  project2
//
//  Created by Brandon Johns on 10/20/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

// CPP program to illustrate
// User-defined Signal Handler






#include<stdio.h>
#include<signal.h>
#include<stdbool.h>
#include<stdlib.h>
#include<unistd.h>



int main(int argc, char **argv)
{
   
    /// the arguement count cannot equal 2
    
    if (argc != 2)
    {
        /// calls for the number of prcces
        printf("how many processes do you want to check \n");
        return 0;
    }

    // incase the user inserts a string this converts it to an int
    int n = atoi(argv[1]);
    // loop 2 * n time
    
    /// this for loop runs the string/ int for how many proceces
    for (int i = 0; i < 2 * n; i++)
    {
        // this creates fork and if the fork = 0 then it runs the name of the process and then exits
        if (fork() == 0)
        {
            // print pid
            printf("I am process %d\n", getpid());
            // ends child proccess 
            exit(0);
        }

    }
}


