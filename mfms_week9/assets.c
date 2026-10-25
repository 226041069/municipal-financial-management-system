#ifndef ASSETS_H
#define ASSETS_H

typedef struct {
    int id;
    char name[50];
    double value;
    char location[30];
} Asset;

void addAsset(Asset *asset);
void displayAsset(const Asset *asset);
int saveAssetsText(const char *filename, const Asset assets[], int count);
int loadAssetsText(const char *filename, Asset assets[], int *count);

#endif
