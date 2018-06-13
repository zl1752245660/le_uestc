#ifndef __FFJPEG_BMP_H__
#define __FFJPEG_BMP_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ���Ͷ��� */
/* BMP ��������Ͷ��� */
typedef struct
{
    int   width;   /* ��� */
    int   height;  /* �߶� */
    int   stride;  /* ���ֽ��� */
    void *pdata;   /* ָ������ */
} BMP;

/* �������� */
int  bmp_load  (BMP *pb, char *file);
int  bmp_create(BMP *pb, int w, int h);

int  bmp_save(BMP *pb, char *file);
void bmp_free(BMP *pb);

#ifdef __cplusplus
}
#endif

#endif

