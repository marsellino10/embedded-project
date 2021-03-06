#ifndef RACE_H
#define	RACE_H

int count_= 0;

int h;
int r1,r2,v1,v2;
int x, flag1, flag2, lives;

const unsigned char player[] ={
 0x42, 0x4D, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80,
 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF,
 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00,
 0x00, 0xFF, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0xFF,
};

const unsigned char cars[] ={
 0x42, 0x4D, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x80, 0xFF, 0x00, 0x80,
 0x00, 0xFF, 0x00, 0x80, 0x80, 0xFF, 0x80, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x80, 0xFF, 0x80, 0x80, 0x00, 0xFF, 0x80, 0x80, 0x80, 0xFF, 0xC0, 0xC0, 0xC0, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF,
 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x0F, 0xF0, 0xFF, 0x00, 0x00, 0x00, 0xFF,
};

const unsigned char border[] ={
 0x42, 0x4D, 0xD6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E,
 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E,
 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E,
 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E,
 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E,
 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0x0E, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF,
};

const unsigned char heart[] ={ 
 0x42, 0x4D, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 
 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 
 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 
};

#define BORDERW    ((unsigned char)BORDER[18])
#define BORDERH    ((unsigned char)BORDER[22])
#define PLAYERW          ((unsigned char)player[18])
#define PLAYERH          ((unsigned char)player[22])
#define CARSW        ((unsigned char)cars[18])
#define CARSH        ((unsigned char)cars[22])
#define HEARTW        ((unsigned char)heart[18])
#define HEARTH        ((unsigned char)heart[22])
/* section: functions declarations */
void Enemies(int h, int v1,int v2, int r1, int r2, int lives);



#endif

