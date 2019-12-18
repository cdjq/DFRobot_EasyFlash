/*!
 * @file DFRobot_EasyFlash.h
 * @brief 定义DFRobot_EasyFlash 类的基础结构
 * @n 它包含了这个类的所有函数
 * @n 初始化
 * @n 重新加载分配内存空间
 * @n 读
 * @n 写
 * @n 删除
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [LiYue](yue.li@dfrobot.com)
 * @version  V1.0
 * @date  2019-12-16
 * @url https://github.com/cdjq/DFRobot_EasyFlash
 */
 
#ifndef DF_EASYFLASH_H
#define DF_EASYFLASH_H

#include "easyflash.h"
#include <WString.h>
class DFRobot_EasyFlash
{/*
public:
/*    typef struct efEnv {
        char *key;
        void *value;
        size_t value_len;
    } sEfEnv_t, *sEfEnv_p;

    /* EasyFlash error code */
    typedef enum {
        EF_N0_ERR,
        EF_ERASE_ERR,
        EF_READ_ERR,
        ER_WRITE_ERR,
        ER_ENV_NAME_ERR,
        EF_ENV_FULL,
        EF_ENV_INIT_FAILED,
    } eEfErr_t; 

    /* the flash sector current status */
 /*   typedef enum {
        EF_SECTOR_EMPTY,
        EF_SECTOR_USING,
        EF_SECTOR_FULL,
    } eEfSectorStatus_t;

    /* env status */
/*     typedef enum envStatus {
        ENV_UNUSED,
        ENV_PRE_WRITE,
        ENV_WRITE,
        ENV_PRE_DELETE,
        ENV_DELETED,
        ENV_ERR_HDR,
        ENV_STATUS_NUM,
     } eEnvStatus_t;

    typedef struct envNodeObj {
        eEnvStatus_t status;                      /**< ENV node status, @see nodeStatus_t */
 /*       bool crcIsOk;                             /**< ENV node CRC32 check is OK */
 //       uint8_t nameLen;                          /**< name length */
  //      uint32_t magic;                           /**< magic word('K', 'V', '1', '0') */
 //       uint32_t len;                             /**< ENV node total length (header + name + value),must aligned by EF_WR_GRAN */
    //    uint32_t valueLen;
  /*      char name[EF_ENV_NAME_MAX];
        struct {
            uint32_t start;
            uint32_t value;
        } addr;
    } *sEnvNodeObj_p;	
*/
public:
    EfErrCode begin(void);			
    EfErrCode OptimizeMemory(void);
    EfErrCode formatEasyFlash(void);
	
	#ifdef EF_USING_ENV
    /* supported on ef_env.c */
	EfErrCode setValue(const char *key, const void *valueBuf, size_t bufLen);
    EfErrCode setValue(const char *key, const char *value);
    EfErrCode setValue(const char *key, String &value);
	size_t getValue(const char *key, void *valueBuf, size_t bufLen, size_t *savedValueLen);
    size_t getValue(String &key, void *valueBuf, size_t bufLen, size_t *savedValueLen);
    size_t getValue(const char *key, void *valueBuf, size_t bufLen);
    size_t getValue(String &key, void *valueBuf, size_t bufLen);
    String getValue(const char *key);
    String getValue(String &key);
    EfErrCode delValue(const char *key);
	EfErrCode delValue(String &key);
    #endif

    #ifdef EF_USING_LOG
    /* ef_log.c */
    eEfErr_t efLogRead(size_t index, uint32_t *log, size_t size);
    eEfErr_t efLogWrite(const uint32_t *log, size_t size);
    eEfErr_t efLogClean(void);
    size_t efLogGetUsedSize(void);
    #endif
	/* print */
/*	void efLogDebug(const char *file, const long line, const char *format, ...);
	void efLogInfo(const char *format, ...);
	void efPrint(const char *format, ...);	*/

private:
//    uint32_t efCalcCrc32(uint32_t crc, const void *buf, size_t size);
};

#endif /* DF_EASYFLASH_H */