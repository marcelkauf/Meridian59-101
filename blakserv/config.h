// Meridian 59, Copyright 1994-2012 Andrew Kirmse and Chris Kirmse.
// All rights reserved.
//
// This software is distributed under a license that is described in
// the LICENSE file that accompanies it.
//
// Meridian is a registered trademark.
/*
 * config.h
 *
 */

#ifndef _CONFIG_H
#define _CONFIG_H

/* valid config ids */
enum 
{ 
   PATH_GROUP,
   PATH_BOF, PATH_MEMMAP, PATH_RSC, PATH_ROOMS, PATH_MOTD, 
   PATH_CHANNEL, PATH_LOADSAVE, PATH_FORMS, PATH_KODBASE,
   PATH_PACKAGE_FILE,

   SOCKET_GROUP,
   SOCKET_PORT, SOCKET_MAINTENANCE_PORT, SOCKET_MAINTENANCE_MASK, 
   SOCKET_DNS_LOOKUP, SOCKET_NAGLE, SOCKET_BLOCK_TIME,

   CHANNEL_GROUP,
   CHANNEL_DEBUG_DISK, CHANNEL_ERROR_DISK, CHANNEL_LOG_DISK,
   CHANNEL_FLUSH,

   GUEST_GROUP,
   GUEST_ACCOUNT, GUEST_CREDITS, GUEST_MAX, GUEST_TOO_MANY, GUEST_SERVER_MIN,
   GUEST_SERVER_MAX,

   LOGIN_GROUP,
   LOGIN_MAX_ATTEMPTS, LOGIN_MIN_VERSION, LOGIN_OLD_VERSION_STR,
   LOGIN_INVALID_VERSION, LOGIN_INVALID_VERSION_STR, LOGIN_SUSPEND_STR,
   LOGIN_MAX_PER_IP, LOGIN_TOO_MANY_PER_IP_STR,

   INACTIVE_GROUP,
   INACTIVE_SYNCHED, INACTIVE_TRANSFER, INACTIVE_SELECTCHAR, INACTIVE_GAME,
   INACTIVE_OVERRIDE,

   MOTD_GROUP,
   MOTD_DEFAULT,

   CREDIT_GROUP,
   CREDIT_DRAIN_AMOUNT, CREDIT_DRAIN_TIME, CREDIT_WARN1, CREDIT_WARN2,
   CREDIT_INIT, CREDIT_ADMIN,

   FILE_GROUP,
   FILE_ALL_RESOURCE, 

   SESSION_GROUP,
   SESSION_MAX_ACTIVE, SESSION_MAX_CONNECT, SESSION_BUSY,

   LOCK_GROUP,
   LOCK_DEFAULT,

   MEMORY_GROUP,
   MEMORY_SIZE_CLASS_HASH,
   MEMORY_SIZE_CLASS_NAME_HASH,
   MEMORY_SIZE_RESOURCE_HASH,
   MEMORY_SIZE_RESOURCE_NAME_HASH,
   MEMORY_SIZE_PROPERTIES_NAME_HASH,

   AUTO_GROUP,
   AUTO_GARBAGE_TIME, AUTO_GARBAGE_PERIOD, AUTO_SAVE_TIME, AUTO_SAVE_PERIOD,
   AUTO_KOD_TIME,AUTO_KOD_PERIOD,
   AUTO_INTERFACE_UPDATE,
   AUTO_TRANSMITTED_TIME, AUTO_TRANSMITTED_PERIOD,
   AUTO_RESET_POOL_TIME, AUTO_RESET_POOL_PERIOD,
   AUTO_CHECK_PORTAL_TIME, AUTO_CHECK_PORTAL_PERIOD,

   EMAIL_GROUP,
   EMAIL_LISTEN, EMAIL_PORT, EMAIL_ACCOUNT_CREATE_NAME, EMAIL_ACCOUNT_DELETE_NAME,
   EMAIL_LOCAL_MACHINE_NAME,EMAIL_HOST,EMAIL_NAME,

   UPDATE_GROUP,
   UPDATE_CLIENT_MACHINE, UPDATE_CLIENT_FILE, UPDATE_PACKAGE_MACHINE,
   UPDATE_PACKAGE_PATH, UPDATE_DOWNLOAD_REASON, UPDATE_DEMO_BUTTON,

   CONSOLE_GROUP,
   CONSOLE_ADMINISTRATOR, CONSOLE_CAPTION,

   RIGHTS_GROUP,
   RIGHTS_GOROOM, RIGHTS_GOROOMBYNUM, RIGHTS_GOPLAYER, RIGHTS_GETPLAYER,

   CONSTANTS_GROUP,  
   CONSTANTS_ENABLED, CONSTANTS_FILENAME,

   PORTAL_GROUP,
   PORTAL_ENABLED, PORTAL_IGNORE, PORTAL_MACHINE, PORTAL_PORT,
   PORTAL_SERVER_NUMBER, PORTAL_ERROR_REPORT,

   ADVERTISE_GROUP,
   ADVERTISE_FILE1, ADVERTISE_URL1, ADVERTISE_FILE2, ADVERTISE_URL2,

   DEBUG_GROUP,
   DEBUG_SMTP, DEBUG_CANMOVEINROOM, DEBUG_HEAP, DEBUG_TRANSMITTED_BYTES,
   DEBUG_HASH, DEBUG_PORTAL, DEBUG_INITPROPERTIES, DEBUG_INITLOCALS,
   DEBUG_UNINITIALIZED,

   SECURITY_GROUP,
   SECURITY_LOG_SPOOFS, SECURITY_HANGUP_SPOOFS, SECURITY_REDBOOK_RSC,

   SERVICE_GROUP,
   SERVICE_ENABLED,
   SERVICE_MACHINE, SERVICE_DIRECTORY, SERVICE_USERNAME, SERVICE_PASSWORD,

   BLAKOD_GROUP,
   BLAKOD_MAX_STATEMENTS,
   
   NUM_CONFIG_VALUES
};

enum
{
   INVALID_CONFIG = -1
};

/* valid config types */
enum { CONFIG_NONE, CONFIG_GROUP, CONFIG_STR, CONFIG_INT, CONFIG_PATH, CONFIG_BOOL };


typedef struct
{
   int config_id;
   int is_dynamic;
   int config_type;
   union
   {
      char *config_str_value; /* for CONFIG_STR and CONFIG_PATH */
      int config_int_value; /* for CONFIG_INT and CONFIG_BOOL */
   };
} config_node;

void InitConfig(void);
void ResetConfig(void);
config_node * GetConfigByID(int config_id);
void ForEachConfigNode(void (*callback_func)(config_node *c,const char *config_name,const char *default_str));

int ConfigInt(int config_id);
char * ConfigStr(int config_id);
Bool ConfigBool(int config_id);

char * LockConfigStr(int config_id);
void UnlockConfigStr(void);

int GetConfigIDByGroupAndName(char *group,char *name);
void SetConfigInt(int config_id,int new_value);
void SetConfigBool(int config_id,Bool new_value);
void SetConfigStr(int config_id,char *new_value);

void LoadConfig(void);

#endif
