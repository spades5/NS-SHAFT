#include <stdio.h>
#include <string.h>

#define countryTotal 21

char *country[countryTotal] = {
	"China",
	"Japan",
	"Korea",
	"India",
	"Indonesia",
	"Malaysia",
	"Singapore",
	"Thailand",
	"Viet Nam",
	"Taiwan",
	"Mexico",
	"Brazil",
	"Canada",
	"USA",
	"the United Kingdom",
	"Italy",
	"Spain",
	"France",
	"Germany",
	"Australia",
	"New Zealand"
};

int population[countryTotal] = {
	1425887, 123952, 51816, 1417173, 275501,
	33938, 5976, 71697, 98187, 23893, 127504,
	215313, 38454, 338290, 67509, 59037, 47559,
	64627, 83370, 26177, 5185
};

void indexOfList(){
    printf("Welcome to the World Population Database!\n");
    char name[500];
    while(1){
        printf("\nInput a line (\"quit\" to exit):");
        fgets(name,sizeof(name),stdin); strtok(name,"\r\n");

        if (strcmp(name, "quit") == 0) {
            break;
        }
            int found = 0;
            for (int i=0; i < countryTotal; i++) {
                if (strcasecmp(country[i], name) == 0){
                    found = 1;
                    printf("The population of the %s is %d thousands\n",country[i],population[i]);
                    break;
                }
            }
        if (!found){
            printf("Sorry, we cannot find [%s] in our database.\n",name);
        }
    }

    printf("\nThank you for using World Population Database!");
}

int main()
{
    indexOfList();
    return 0;
}
