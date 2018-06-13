#ifndef __FFJPEG_HUFFMAN_H__
#define __FFJPEG_HUFFMAN_H__

/* ����ͷ�ļ� */
#include "stdefine.h"

#ifdef __cplusplus
extern "C" {
#endif

/* �������� */
#define MAX_HUFFMAN_CODE_LEN  16

extern const BYTE STD_HUFTAB_LUMIN_AC[];
extern const BYTE STD_HUFTAB_LUMIN_DC[];
extern const BYTE STD_HUFTAB_CHROM_AC[];
extern const BYTE STD_HUFTAB_CHROM_DC[];

/* ���Ͷ��� */
/* ����������Ͷ��� */
typedef struct
{
    int symbol; /* ���� */
    int freq;   /* Ƶ�� */
    int group;  /* ���� */
    int depth;  /* �볤 */
    int code;   /* ���� */
} HUFCODEITEM;

/* ���������Ͷ��� */
typedef struct
{
    BYTE         huftab[MAX_HUFFMAN_CODE_LEN + 256]; /* �������� */
    int          first [MAX_HUFFMAN_CODE_LEN];       /* first    */
    int          index [MAX_HUFFMAN_CODE_LEN];       /* index    */
    HUFCODEITEM  codelist[256];/* ����� */
    void        *input;        /* input bit stream  */
    void        *output;       /* output bit stream */
} HUFCODEC;


/* �������� */
/* ��׼�ķ���Ƶ��ͳ���� */
void huffman_stat_freq(HUFCODEITEM codelist[256], void *stream);


/* ���� */
/*
  ���뷽����
      1. ��ʼ�� HUFCODEC �е� freqlist ��Ա�����Բ���
         huffman_stat_freq ����Ƶ��ͳ�ƣ�Ҳ�����Լ���
         ��ʵ��Ƶ��ͳ��

      2. ���� huffman_encode_begin ������������ huftab,
         codelist �ֱ��Ӧ�˹������� (JPEG format)��
         �����

      3. ָ�� srcbitstr �� destbitstr �ֱ����������
         �е�Դ��������Ŀ��������

      4. ָ��������Ȼص�����ָ�� pps, ���ڱ�����ȿ�
         ��

      5. ���� huffman_encode_run ��������Զ��ı����
         ������Ľ��������� srcbitstr �� destbitstr ��
         ����β��

      6. ���� huffman_encode_done ��������������

      7. Ҳ���Բ�ͨ�� huffman_encode_run ���б��룬��
         huffman_encode_begin �Ժ��û������Լ���
         �� codelist ��ɱ������
 */
// flag == 0, init from code freq list
// flag == 1, init from huffman table
void huffman_encode_init(HUFCODEC *phc, int flag);
void huffman_encode_done(HUFCODEC *phc);
BOOL huffman_encode_run (HUFCODEC *phc);

/* һ��ֻ����һ������ */
BOOL huffman_encode_step(HUFCODEC *phc, int symbol);


/* ���� */
/*
  ���뷽����
      1. ��ʼ�� HUFCODEC �е� huftab ��Ա��hufman
         �� JPEG format �ķ�ʽ��������

      2. ���� huffman_decode_begin ������� huftab
         ���� first �� index ������

      3. ָ�� srcbitstr �� destbitstr �ֱ�������
         �����е�Դ��������Ŀ��������

      4. ָ��������Ȼص�����ָ�� pps, ���ڽ����
         �ȿ���

      3. ���� huffman_decode_run ��������Զ��Ľ���
         ��������Ľ��������� srcbitstr �� destbitstr
         ������β��

      6. ���� huffman_decode_done ��������������

      7. Ҳ����ͨ�� huffman_decode_one ���е���
         �Ĺ���������������ú���ÿ�ε���ֻ�����
         �����н����һ������
 */
void huffman_decode_init(HUFCODEC *phc);
void huffman_decode_done(HUFCODEC *phc);
BOOL huffman_decode_run (HUFCODEC *phc);

/* һ��ֻ����һ������ */
int  huffman_decode_step(HUFCODEC *phc);

#ifdef __cplusplus
}
#endif

#endif






