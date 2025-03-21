#include <stdio.h>
#include <string.h>

typedef struct {
   char engName[100];
   char sciName[100];
   int avgLength;
   int avgWeight;
   char environment;
} FishData;


int main()
{
    printf("Welcome to the NTOU Marine Education Encyclopedia!\n");
    FishData fish[5] = {
            {"Milk Fish","Chanos chanos",40,300,'S'},
            {"Black King Fish","Rachycentron canadum",150,40000,'S'},
            {"Grass Carp","Ctenopharyngodon idella",150,35000,'F'},
            {"Gold Head Cichlid","Aulonocara baenschi",15,-1,'F'},
            {"Ocellaris Clownfish", "Amphiprion ocellaris",4,-1,'S'}
        };
    char name[500];
    while(1){
        printf("\nInput the name of fish (\"quit\" to exit): ");
        fgets(name,sizeof(name),stdin); strtok(name,"\r\n");

        if (strcmp(name, "quit") == 0) {
            break;
        }
            int found = 0;
            for (int i=0; i < 5; i++) {
                if (strcasecmp(fish[i].engName, name) == 0){
                    found = 1;
                    if (fish[i].avgWeight != -1){
                        if (fish[i].environment == 'S'){
                            printf("%s (%s): average length %dcm, average weight %dg, seawater fish.\n",fish[i].engName,fish[i].sciName,fish[i].avgLength,fish[i].avgWeight);
                        }
                        if (fish[i].environment == 'F'){
                            printf("%s (%s): average length %dcm, average weight %dg, freshwater fish.\n",fish[i].engName,fish[i].sciName,fish[i].avgLength,fish[i].avgWeight);
                        }
                    }
                    else{
                        if (fish[i].environment == 'S'){
                            printf("%s (%s): average length %dcm, seawater fish.\n",fish[i].engName,fish[i].sciName,fish[i].avgLength);
                        }
                        if (fish[i].environment == 'F'){
                            printf("%s (%s): average length %dcm, freshwater fish.\n",fish[i].engName,fish[i].sciName,fish[i].avgLength);
                        }
                    }
                    break;
                }
            }
        if (!found){
            printf("Sorry, we cannot find [%s] in our database.\n",name);
        }
    }

    printf("\nThank you for using the NTOU Marine Education Encyclopedia!");
    return 0;
}
