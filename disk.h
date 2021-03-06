#ifndef DISK_H
#define DISK_H

#include <stdio.h>
//atoi
#include <stdlib.h>
//directorios
#include <dirent.h>
//crear directorios
#include <sys/stat.h>
//comparacion de cadenas
#include <string.h>
//timeq
#include <time.h>
#include <qdebug.h>
//para el diccionario
#include <qmap.h>
#include <qqueue.h>
#include <qstack.h>
//validaciones
#include <validations.h>
#include <plotter.h>
//*************Diccionario de discos montados************//
static QMap<QString,char> mounted_disks;
static QMap<QString,Partition> mounted_partitions;
//******variable de sesion*******//
static user cookie;

class disk : public validations
{
public:
disk();
void copyFile(Metadata data);
void makeDisk(Metadata data);
void renameFile(Metadata data);
void fDisk(Metadata data);
void removeDisk(Metadata data);
void mountDisk(Metadata data);
void unmountDisk(QString unmount_id_partition);
void makeGroup(Metadata data);
void removeGroup(Metadata data);
void formatDisk(Metadata data);
void makeReport(Metadata data);
void makeDir(Metadata data);
void makeFile(Metadata data);
void makeUser(Metadata data);
void removeUser(Metadata data);
void showFile(Metadata data, bool gnt_report);
void chmod(Metadata data);
void recovery(Metadata data);
void loss(Metadata data);
void login(Metadata data);
void logout();

private:
void createPartition(Metadata data,FILE* file,Mbr mbr);
};

#endif // DISK_H
