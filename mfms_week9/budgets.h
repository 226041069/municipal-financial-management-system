#include <stdio.h>
#include <string.h>

#include "assets.h"
#include "utilities.h"

void addAsset(Asset *asset)
{
    asset->id = inputInt("Enter asset ID: ");
    readString("Enter asset name: ", asset->name, sizeof(asset->name));
    asset->value = inputDouble("Enter asset value: ");
    readString("Enter asset location: ", asset->location, sizeof(asset->location));
}

void displayAsset(const Asset *asset)
{
    printf("Asset ID: %d\n", asset->id);
    printf("Name: %s\n", asset->name);
    printf("Value: %.2f\n", asset->value);
    printf("Location: %s\n", asset->location);
}

int saveAssetsText(const char *filename, const Asset assets[], int count)
{
    FILE *fp = fopen(filename, "w");
    if (!fp)
    {
        perror("Error opening assets file for writing");
        return 0;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d|%s|%.2f|%s\n",
                assets[i].id,
                assets[i].name,
                assets[i].value,
                assets[i].location);
    }

    fclose(fp);
    return 1;
}

int loadAssetsText(const char *filename, Asset assets[], int *count)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        perror("Error opening assets file for reading");
        return 0;
    }

    *count = 0;
    while (*count < 100 && fscanf(fp, "%d|%49[^|]|%lf|%29[^|\n]\n",
                                  &assets[*count].id,
                                  assets[*count].name,
                                  &assets[*count].value,
                                  assets[*count].location) == 4)
    {
        (*count)++;
    }

    fclose(fp);
    return 1;
}
