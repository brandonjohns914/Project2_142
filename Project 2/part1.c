//
//  main.c
//  project2
//
//  Created by Brandon Johns on 10/20/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//







#include<stdio.h>
#include<signal.h>
#include<stdbool.h>
#include<stdlib.h>
#include<unistd.h>

/// press control c to see iteration

// global bool and int
static bool flag = false;
static int i = 1;

/// part 1 function
void part1(void);

/// finds the signal
void signal_hand(int signal)
{
    /// flag cannnot == falg
flag=!flag;
   printf("this is the signal  %d %d\n", signal,flag);
    /// if the signal == user signal kill the pid and siguser
   if(signal==SIGUSR1){
   kill(getpid(),SIGUSR1);
   }
}

/// function to call part 1
void part1(void)
{
    //// calls the signal using the sginal function
    signal(SIGINT, signal_hand);
    signal(SIGUSR1, signal_hand);
    
    /// infinte loop while true always runs
    while (1)
    {
        /// flag runs while the flag runs.
        while(flag)
        {
            //// printing the signal and adding signal by 1
            printf("iteration of signal %d\n",i);
            i++;
            /// sleeps for 2 seconds using the sleep function 
            sleep(2);
        }
    };
}

int main(int argc, char **argv)
{
    part1();
}


