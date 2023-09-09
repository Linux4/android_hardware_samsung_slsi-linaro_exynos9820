//------------------------------------------------------------------------------
/// @file  sc_ipc_packet.h
/// @ingroup  include
///
/// @brief  Declarations of the IPC packet shared between SCore and other IPs
///
/// This file declares IPC packet struct about those. IPC packet is the information
/// shared between Host and other external IPs to execute SCore kernel.
///
/// @internal
/// @author  Dongseok Han<ds0920.han@samsung.com>
///
/// @section changelog Change Log
/// 2016/06/01 Dongseok Han created
///
/// @section copyright_section Copyright
/// &copy; 2016, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------
#ifndef SCORE_COMMON_INCLUDE_SC_IPC_PACKET_H_
#define SCORE_COMMON_INCLUDE_SC_IPC_PACKET_H_

#include "sc_global.h"

typedef enum {
  NONE              = 0x0, //A packet doesn't have next packet in it's payload
  KERNEL            = 0x1, //A packet has next kenel packet in it's payload
  RESULT            = 0x2, //A packet has next result packet in it's payload
  PROLOGUE          = 0x3, //The Identifer to use within the score(prologue packet)
  INTERNAL          = 0x4, //The Identifer to use within the score(internal packet)
  STREAM            = 0x5, //A packet has next stream kernel packet in it's payload
  EXTKERNEL         = 0x6, //A packet has nex kenel packet includes new features
                           //(ex:priority) in it's payload
  SECTION           = 0x7, //The Identifer to use within the score(internal packet)
  VSSIZE            = 0x8, //The Identifer to use within the score(internal packet)
  PACKETEND                //The end of enum value.
} PacketType, packet_type;

typedef enum {
  IHM_PKT_V1        = 0x1,
  IHM_PKT_V2        = 0x2,
  IHM_PKT_V3        = 0x3,
} ScPacketVersion, score_packet_version;

/// @brief  Packet version Inter Host-MC at the compile time
#define IHM_PKT_VER     IHM_PKT_V3

/// @brief  Packet header size (in byte)
#define PACKET_MAIN_HEADER_SIZE                    (sizeof(sc_packet_header))

/// @brief  Packet header size (in word)
#define PACKET_MAIN_HEADER_SIZE_IN_WORD            (PACKET_MAIN_HEADER_SIZE>>2)

/// @brief  Kernel packet header size (in byte)
#define PACKET_KERNEL_HEADER_SIZE                  (sizeof(sc_kernel_packet_header))

/// @brief  Kernel packet header size (in word)
#define PACKET_KERNEL_HEADER_SIZE_IN_WORD          (PACKET_KERNEL_HEADER_SIZE>>2)

/// @brief  Extend kernel packet header size (in byte)
#define PACKET_EXTEND_KERNEL_HEADER_SIZE           (sizeof(sc_extend_kernel_packet_header))

/// @brief  Extend kernel packet header size (in word)
#define PACKET_EXTEND_KERNEL_HEADER_SIZE_IN_WORD   (PACKET_EXTEND_KERNEL_HEADER_SIZE>>2)

/// @brief  Result packet header size (in byte)
#define PACKET_RESULT_HEADER_SIZE                  (sizeof(sc_result_packet_header))

/// @brief  Result packet header size (in word)
#define PACKET_RESULT_HEADER_SIZE_IN_WORD          (PACKET_RESULT_HEADER_SIZE>>2)

/// @brief  SCQ max request size (in word)
#define MAX_REQUEST_SIZE_IN_WORD                   (512)

/// @brief  SCQ max request size (in byte)
#define MAX_REQUEST_SIZE                           (MAX_REQUEST_SIZE_IN_WORD<<2)

#define MAX_PAYLOAD_SIZE (MAX_REQUEST_SIZE_IN_WORD - (sizeof(sc_packet_header) >> 2)) ///<(in words)
#define SCBUFFER_ADDR_OFFSET (3) //WORD offset fron start of sc_buffer to sc_buffer.addr
#define SCBUFFER_ADDR_OFFSET4 (12) //BYTE offset fron start of sc_buffer to sc_buffer.addr
#define IDENTIFIER_OFFSET (4) //BYTE offset of Identifier in protocol

/// @brief  IPC packet header contains meta information for sending payload
typedef struct _sc_packet_header {
  unsigned int next_type:   8;    ///< Packet type of following payload
  unsigned int src:         5;    ///< Source device id
  unsigned int dst:         5;    ///< Destination device id
  unsigned int version:     5;    ///< Version of SCore
  unsigned int reserved:    9;    ///< RESERVED
}sc_packet_header;

typedef struct _sc_kernel_packet_header {
  unsigned int next_type:   4;      ///< Packet type of following payload
  unsigned int size:        11;     ///< Size of sc_kernel_packet (in byte)
  unsigned int kernel_id:   9;      ///< Packet type of current payload
  unsigned int task_id:     8;      ///< ID of the task requested
}sc_kernel_packet_header;

typedef struct _sc_extend_kernel_packet_header {
  unsigned int next_type: 4;      ///< Packet type of following payload
  unsigned int size:      11;     ///< Size of sc_kernel_packet (in byte)
  unsigned int kernel_id: 9;      ///< Packet type of current payload
  unsigned int task_id:   8;      ///< ID of the task requested
  unsigned int priority:  8;      ///< Level of priority
  unsigned int vdis_sync: 1;      ///< vdis kernel sync
  unsigned int bound:     2;      ///< CPU / IO / IO_EXCL_TCM bound
  unsigned int block:     2;      ///< Block lower priority task
  unsigned int task_split:1;      ///< Flag of task split
  unsigned int single_kc: 1;      ///< Use only one computing core
  unsigned int vs_size:   2;      ///< Size of vector stack
  unsigned int reserved:  15;     ///< RESERVED
}sc_extend_kernel_packet_header;

typedef struct _sc_result_packet_header {
  unsigned int next_type:   4;      ///< Packet type of following payload
  unsigned int size:        11;     ///< Size of sc_result_packet (in byte)
  unsigned int kernel_id:   9;      ///< ID of ther kernel returned
  unsigned int task_id:     8;      ///< ID of the task returned
  unsigned int ret_code;            ///< Result of the task returned
  unsigned int priority;            ///< Priority of the task returned
}sc_result_packet_header;

/// @brief  IPC packet payload
typedef struct _sc_packet_payload {
  unsigned int payload[MAX_PAYLOAD_SIZE];
}sc_packet_payload;

/// @brief  IPC packet contains packet header and payload
typedef struct _sc_packet {
  sc_packet_header header;
  sc_packet_payload p[0];
}sc_packet;

/// @brief  IPC packet contains meta information for calling SCore kernel
typedef struct _sc_kernel_packet {
  sc_kernel_packet_header header;
  sc_packet_payload p[0];
}sc_kernel_packet;

/// @brief  IPC packet contains meta information for calling SCore extend kernel
typedef struct _sc_extend_kernel_packet {
  sc_extend_kernel_packet_header header;
  sc_packet_payload p[0];
}sc_extend_kernel_packet;

typedef struct _sc_result_packet {
  sc_result_packet_header header;
  sc_packet_payload p[0];
}sc_result_packet;

#endif
