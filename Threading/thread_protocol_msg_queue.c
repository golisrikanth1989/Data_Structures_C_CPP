#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *phy_layer(void *v1)
{   
   return 0;
}

void *mac_layer(void *v1)
{   
   return 0;
}

void *rlc_layer(void *v1)
{   
   return 0;
}

void *pdcp_layer(void *v1)
{   
   return 0;
}

void *sdap_layer(void *v1)
{   
   return 0;
}

void *rrc_layer(void *v1)
{   
   return 0;
}

void *rrc_layer(void *v1)
{   
   return 0;
}

//int main(int argc, char * argv[])
int main()
{
    // Creating a thread varibles or IDs for PHY,MAC,RLC,PDCP,SDAP,RRC and NAS
    pthread_t phy_thread,mac_thread,rlc_thread,pdcp_thread,sdap_thread,rrc_thread,nas_thread;

    // Creating a thread for each layers
    pthread_create(&phy_thread,  NULL, phy_layer,  NULL);
    pthread_create(&mac_thread,  NULL, mac_layer,  NULL);
    pthread_create(&rlc_thread,  NULL, rlc_layer,  NULL);
    pthread_create(&pdcp_thread, NULL, pdcp_layer, NULL);
    pthread_create(&sdap_thread, NULL, sdap_layer, NULL);
    pthread_create(&rrc_thread,  NULL, rrc_layer,  NULL);
    pthread_create(&nas_thread,  NULL, nas_layer,  NULL); 
    
    // Wait for all threads to finish
    pthread_join(phy_thread,  NULL);
    pthread_join(mac_thread,  NULL);
    pthread_join(rlc_thread,  NULL);
    pthread_join(pdcp_thread, NULL);
    pthread_join(sdap_thread, NULL);
    pthread_join(rrc_thread,  NULL);
    pthread_join(nas_thread,  NULL);
    
    return 0;
}