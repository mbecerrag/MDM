/*!
 * \file mdm_device_dslam_siemens_hix5300.h Defines for DSLAM SIEMENS HIX 5300.
 *
 * \author Marcelo Gornstein <marcelog@gmail.com>
 */
#ifndef	_MDM_DEVICE_DSLAM_SIEMENS_HIX5300_H_
#define	_MDM_DEVICE_DSLAM_SIEMENS_HIX5300_H_

#include	<mdm_connection.h>
#include	<mdm_device.h>

/*! Commands. */
typedef enum
{
/* 0  */	MDM_DSLAM_SIEMENS_HIX5300_CMD_NOP,
/* 1  */	MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_RUNNING_CONFIG,
/* 2  */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_SYSTEM_VERSION,
/* 3  */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_NTP_CLIENT,
/* 4  */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_ALARM_LIST,
/* 5  */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_UPGRADE,
/* 6  */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_UPGRADE_TABLE,
/* 7  */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_SYSLOG,
/* 8  */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_STATUS_FAN,
/* 9  */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_SLOTS,
/* 10 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_UPTIME,
/* 11 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_MEMORY,
/* 12 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_PVID,
/* 13 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_ATM_VC,
/* 14 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_PORT_DETAIL,
/* 15 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_PORT_ATUC,
/* 16 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_PORT_ATUR,
/* 17 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_PORT_LINE_TABLE,
/* 18 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_PORT_LINE_CONFIG,
/* 19 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_PROFILES,
/* 20 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_ARP,
/* 21 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_NETIF,
/* 22 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_SHOW_CPULOAD,
/* 23 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_CFG_TIMEZONE,
/* 24 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_CFG_SYSLOG,
/* 25 */    MDM_DSLAM_SIEMENS_HIX5300_CMD_CFG_NOSYSLOG,
	MDM_DSLAM_SIEMENS_HIX5300_CMD_DUMMY
} mdm_device_cmd_dslam_siemens_hix5300_t;

/*! Options for dslam connection. */
typedef struct
{
	mdm_connection_type_t connection_type; /*!< Connection type. */
	char target[256]; /*!< If serial, filename. If network, host:port. */
	char username[16]; /*!< Username for login. */
	char password[16]; /*!< Password for login. */
	char enable[16]; /*!< Password for enable. */
	int to_recv; /*!< If blocking >= 0, wait at most this amount of milliseconds
		before timeout. If -1, will block. */
	int to_connect; /*!< If < 1 timeouts when os decides, otherwise, time in
		milliseconds for timeouting a connect(). */
} mdm_device_dslam_siemens_hix5300_options_t;

/*! This will hold internal data regarding the current connection. */
typedef struct
{
	char prompt[80];
	int promptlen; /*!< We need the prompt length because when the dslam
	echoes our issued command, it adds the prompt length to make the command
	fit in 80 columns. */
} mdm_device_dslam_siemens_hix5300_data_t;

/*!
 * Used to post process dslam responses.
 * See #mdm_device_dslam_siemens_hix5300_post_exec_t
 */
typedef void (*mdm_device_dslam_siemens_hix5300_post_exec_t)(
	mdm_device_descriptor_t *, mdm_operation_result_t *
);

extern const char *MDM_DEVICE_CMDNAME_DSLAM_SIEMENS_HIX5300_STR[];
extern const char *MDM_DEVICE_CMD_DSLAM_SIEMENS_HIX5300_STR[];

extern void mdm_device_dslam_siemens_hix5300_open(
	mdm_device_descriptor_t *, mdm_connection_type_t, mdm_operation_result_t *
);
extern void mdm_device_dslam_siemens_hix5300_exec(
	mdm_device_descriptor_t *, mdm_operation_result_t *
);

extern void mdm_device_dslam_siemens_hix5300_close(
	mdm_device_descriptor_t *, mdm_operation_result_t *
);

extern void mdm_device_dslam_siemens_hix5300_new(
	mdm_device_t *, mdm_operation_result_t *
);
extern void mdm_device_dslam_siemens_hix5300_free(mdm_device_t *);

extern void mdm_device_dslam_siemens_hix5300_prepare_exec(
	mdm_device_descriptor_t *, mdm_device_cmd_t,
	const char *, mdm_operation_result_t *
);

extern void mdm_device_dslam_siemens_hix5300_post_exec(
	mdm_device_descriptor_t *,
	mdm_device_cmd_t, mdm_operation_result_t *
);

extern void mdm_device_dslam_siemens_hix5300_check_error(
	mdm_device_descriptor_t *, mdm_operation_result_t *
);

#endif