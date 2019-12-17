/*!
 * @file DFRobot_EasyFlash.cpp
 * @brief 实现DFRobot_EasyFlash 类的功能
 * @n 它包含了这个类的所有函数
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Ouki](ouki.wang@dfrobot.com)
 * @version  V1.0
 * @date  2019-12-14
 * @url https://github.com/ouki-wang/DFRobot_Sensor
 */
 
#include "DFRobot_EasyFlash.h"
  
inline eFfErr_t DFRobot_EasyFlash::begin(void)
{
	return easyflash_init(void);
}

inline eEfErr_t DFRobot_EasyFlash::OptimizeMemory(void)
{
	return ef_load_env(void);
}

inline eEfErr_t DFRobot_EasyFlash::formatEasyFlash(void)
{
    return ef_env_set_default(void);
}




inline eEfErr_t DFRobot_EasyFlash::setValue(const char *key, const void *valueBuf, size_t bufLen)
{
	return ef_set_env_blob(key, valueBuf, bufLen);
}

inline eEfErr_t DFRobot_EasyFlash::setValue(const char *key, const char *value)
{
    return ef_set_env_blob(key, value, strlen(value));
}

inline eEfErr_t DFRobot_EasyFlash::setValue(const char *key, String &value)
{
    return ef_set_env_blob(key, value.buffer, value.len);
}




inline size_t DFRobot_EasyFlash::getValue(const char *key, void *valueBuf, size_t bufLen, size_t *savedValueLen)
{   
	return ef_get_env_blob(key, valueBuf, bufLen, savedValueLen);
}

inline size_t DFRobot_EasyFlash::getValue(String key, void *valueBuf, size_t bufLen, size_t *savedValueLen)
{   
	return ef_get_env_blob(key.buffer, valueBuf, bufLen, savedValueLen);
}

inline size_t DFRobot_EasyFlash::getValue(const char *key, void *valueBuf, size_t bufLen)
{   
	return ef_get_env_blob(key, valueBuf, bufLen, NULL);
}

inline size_t DFRobot_EasyFlash::getValue(String &key, void *valueBuf, size_t bufLen)
{   
	return ef_get_env_blob(key.buffer, valueBuf, bufLen, NULL);
}

static bool ef_is_str(uint8_t *value, size_t len)
{
#define __is_print(ch)       ((unsigned int)((ch) - ' ') < 127u - ' ')
    size_t i;

    for (i = 0; i < len; i++) {
        if (!__is_print(value[i])) {
            return false;
        }
    }
    return true;
}

String DFRobot_EasyFlash::getValue(const char *key)
{   
    static char value[EF_STR_ENV_VALUE_MAX_SIZE + 1];
    size_t get_size;

    if ((get_size = ef_get_env_blob(key, value, EF_STR_ENV_VALUE_MAX_SIZE, NULL)) > 0) {
        /* the return value must be string */
        if (ef_is_str((uint8_t *)value, get_size)) {
            value[get_size] = '\0';
            return String(value);
        } else {
            EF_INFO("Warning: The ENV value isn't string. Could not be returned\n");
            return NULL;
        }
    }

    return NULL;
}

String DFRobot_EasyFlash::getValue(String &key)
{   
    static char value[EF_STR_ENV_VALUE_MAX_SIZE + 1];
    size_t get_size;

    if ((get_size = ef_get_env_blob(key.buffer, value, EF_STR_ENV_VALUE_MAX_SIZE, NULL)) > 0) {
        /* the return value must be string */
        if (ef_is_str((uint8_t *)value, get_size)) {
            value[get_size] = '\0';
            return String(value);
        } else {
            EF_INFO("Warning: The ENV value isn't string. Could not be returned\n");
            return NULL;
        }
    }

    return NULL;
}



inline eEfErr_t DFRobot_EasyFlash::delValue(const char *key)
{
	return = ef_del_env(key);
}

inline eEfErr_t DFRobot_EasyFlash::delValue(String &key)
{
	return = ef_del_env(key.buffer);
}
























