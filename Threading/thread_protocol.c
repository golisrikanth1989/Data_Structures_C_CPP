#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex_mac;
pthread_mutex_t mutex_rlc;
pthread_mutex_t mutex_pdcp;

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
    
    // Pass the processed data to the RRC layer
    
    pthread_exit(NULL);
}

int main()
{
    pthread_t physical_layer_thread, mac_layer_thread, rlc_layer_thread, pdcp_layer_thread;
    
    pthread_mutex_init(&mutex_mac, NULL);
    pthread_mutex_init(&mutex_rlc, NULL);
    pthread_mutex_init(&mutex_pdcp, NULL);
    
    // Create threads for each layer
    pthread_create(&physical_layer_thread, NULL, physical_layer, NULL);
    pthread_create(&mac_layer_thread, NULL, mac_layer, NULL);
    pthread_create(&rlc_layer_thread, NULL, rlc_layer, NULL);
    pthread_create(&pdcp_layer_thread, NULL, pdcp_layer, NULL);
    
    // Wait for all threads to finish
    pthread_join(physical_layer_thread, NULL);
    pthread_join(mac_layer_thread, NULL);
    pthread_join(rlc_layer_thread, NULL);
    pthread_join(pdcp_layer_thread, NULL);
    
    pthread_mutex_destroy(&mutex_mac);
    pthread_mutex_destroy(&mutex_rlc);
    pthread_mutex_destroy(&mutex_pdcp);
    
    return 0;
}