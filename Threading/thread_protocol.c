#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex_mac;
pthread_mutex_t mutex_rlc;
pthread_mutex_t mutex_pdcp;
pthread_mutex_t mutex_sdap;
pthread_mutex_t mutex_rrc;
pthread_mutex_t mutex_nas;


void *physical_layer()
{
    // Simulating data reception in the physical layer
    printf("Physical layer received data.\n");
    
    // Pass the received data to the MAC layer
    pthread_mutex_lock(&mutex_mac);
    printf("Physical layer passed data to MAC layer.\n");
    pthread_mutex_unlock(&mutex_mac);
    
    pthread_exit(NULL);
}

void *mac_layer()
{
    // Wait for data from the physical layer
    pthread_mutex_lock(&mutex_mac);
    printf("MAC layer received data.\n");
    pthread_mutex_unlock(&mutex_mac);
    
    // Process data in the MAC layer
    
    // Pass the processed data to the RLC layer
    pthread_mutex_lock(&mutex_rlc);
    printf("MAC layer passed data to RLC layer.\n");
    pthread_mutex_unlock(&mutex_rlc);
    
    pthread_exit(NULL);
}

void *rlc_layer()
{
    // Wait for data from the MAC layer
    pthread_mutex_lock(&mutex_rlc);
    printf("RLC layer received data.\n");
    pthread_mutex_unlock(&mutex_rlc);
    
    // Process data in the RLC layer
    
    // Pass the processed data to the PDCP layer
    pthread_mutex_lock(&mutex_pdcp);
    printf("RLC layer passed data to PDCP layer.\n");
    pthread_mutex_unlock(&mutex_pdcp);
    
    pthread_exit(NULL);
}

void *pdcp_layer()
{
    // Wait for data from the RLC layer
    pthread_mutex_lock(&mutex_pdcp);
    printf("PDCP layer received data.\n");
    pthread_mutex_unlock(&mutex_pdcp);
    
    // Process data in the PDCP layer
    pthread_mutex_lock(&mutex_sdap);
    printf("RLC layer passed data to PDCP layer.\n");
    pthread_mutex_unlock(&mutex_sdap);
    // Pass the processed data to the SDAP layer
    
    pthread_exit(NULL);
}


void *sdap_layer()
{
    // Wait for data from the RLC layer
    pthread_mutex_lock(&mutex_sdap);
    printf("SDAP layer received data.\n");
    pthread_mutex_unlock(&mutex_sdap);
    
    // Process data in the SDAP layer
    pthread_mutex_lock(&mutex_rrc);
    printf("RLC layer passed data to PDCP layer.\n");
    pthread_mutex_unlock(&mutex_rrc);
    // Pass the processed data to the RRC layer
    
    pthread_exit(NULL);
}


void *rrc_layer()
{
    // Wait for data from the RLC layer
    pthread_mutex_lock(&mutex_rrc);
    printf("PDCP layer received data.\n");
    pthread_mutex_unlock(&mutex_rrc);
    
    // Process data in the RRC layer
    pthread_mutex_lock(&mutex_rrc);
    printf("RLC layer passed data to PDCP layer.\n");
    pthread_mutex_unlock(&mutex_rrc);
    // Pass the processed data to the NAS layer
    
    pthread_exit(NULL);
}



void *nas_layer()
{
    // Wait for data from the RLC layer
    pthread_mutex_lock(&mutex_nas);
    printf("NAS layer received data.\n");
    pthread_mutex_unlock(&mutex_nas);
    
    // Process data in the NAS layer
    
    // Process data to get the relevant information
    
    pthread_exit(NULL);
}


int main()
{
    pthread_t physical_layer_thread, mac_layer_thread, rlc_layer_thread, pdcp_layer_thread,sdap_layer_thread,rrc_layer_thread,nas_layer_thread;
    
    pthread_mutex_init(&mutex_mac, NULL);
    pthread_mutex_init(&mutex_rlc, NULL);
    pthread_mutex_init(&mutex_pdcp, NULL);
    pthread_mutex_init(&mutex_sdap, NULL);
    pthread_mutex_init(&mutex_rrc, NULL);
    pthread_mutex_init(&mutex_nas, NULL);

    // Create threads for each layer
    pthread_create(&physical_layer_thread, NULL, physical_layer, NULL);
    pthread_create(&mac_layer_thread, NULL, mac_layer, NULL);
    pthread_create(&rlc_layer_thread, NULL, rlc_layer, NULL);
    pthread_create(&pdcp_layer_thread, NULL, pdcp_layer, NULL);
    pthread_create(&sdap_layer_thread, NULL, sdap_layer, NULL);
    pthread_create(&rrc_layer_thread, NULL, rrc_layer, NULL);
    pthread_create(&nas_layer_thread, NULL, nas_layer, NULL);
    
    // Wait for all threads to finish
    pthread_join(physical_layer_thread, NULL);
    pthread_join(mac_layer_thread, NULL);
    pthread_join(rlc_layer_thread, NULL);
    pthread_join(pdcp_layer_thread, NULL);
    pthread_join(sdap_layer_thread, NULL);
    pthread_join(rrc_layer_thread, NULL);
    pthread_join(nas_layer_thread, NULL);
    
    
    pthread_mutex_destroy(&mutex_mac);
    pthread_mutex_destroy(&mutex_rlc);
    pthread_mutex_destroy(&mutex_pdcp);
    pthread_mutex_destroy(&mutex_sdap);
    pthread_mutex_destroy(&mutex_rrc);
    pthread_mutex_destroy(&mutex_nas);
    
    return 0;
}