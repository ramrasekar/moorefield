/*
  Copyright (C) 2010-2014 Intel Corporation.  All Rights Reserved.

  This file is part of SEP Development Kit

  SEP Development Kit is free software; you can redistribute it
  and/or modify it under the terms of the GNU General Public License
  version 2 as published by the Free Software Foundation.

  SEP Development Kit is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with SEP Development Kit; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

  As a special exception, you may use this file as part of a free software
  library without restriction.  Specifically, if other files instantiate
  templates or use macros or inline functions from this file, or you compile
  this file and link it with other files to produce an executable, this
  file does not by itself cause the resulting executable to be covered by
  the GNU General Public License.  This exception does not however
  invalidate any other reasons why the executable file might be covered by
  the GNU General Public License.
*/

#ifndef _VTSS_IPT_H_
#define _VTSS_IPT_H_

#include "vtss_autoconf.h"
#include "transport.h"

/**
// Data Types and Macros
*/

/*
// IPT macro definitions
*/
#define IPT_CONTROL_MSR  0x570
#define IPT_STATUS_MSR   0x571
#define IPT_OUT_BASE_MSR 0x560
#define IPT_OUT_MASK_MSR 0x561

#define IPT_BUF_SIZE     0x1000

/*
// IPT structures
*/

#pragma pack(push, 1)

typedef struct
{
    /// |63:12 PhysAddr|11:10 rsvd|9:6 size|5|4: stop|3|2: int|1|0: end
    unsigned long long entry[1];

} topa_t;

typedef struct
{
    unsigned int flagword;
    unsigned int residx;
    unsigned int cpuidx;
    long long cputsc;
    unsigned short size;
    unsigned short type;

} ipt_trace_record_t;

#pragma pack(pop)

/**
// Function Declarations
*/

int vtss_ipt_init(void);
void vtss_ipt_fini(void);
int vtss_has_ipt_overflowed(void);
void vtss_enable_ipt(void);
void vtss_disable_ipt(void);
void vtss_dump_ipt(struct vtss_transport_data* trnd, int tidx, int cpu, int is_safe);

#endif /* _VTSS_IPT_H_ */
