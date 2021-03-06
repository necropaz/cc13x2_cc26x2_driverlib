/******************************************************************************
*  Filename:       rf_patch_cpe_ieee_802_15_4.h
*  Revised:        $Date: 2017-08-24 11:43:33 +0200 (to, 24 aug 2017) $
*  Revision:       $Revision: 17889 $
*
*  Description: RF core patch for IEEE 802.15.4-2006 support ("IEEE" API command set) in CC13x2 and CC26x2
*
*  Copyright (c) 2015-2017, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/
#ifndef _RF_PATCH_CPE_IEEE_802_15_4_H
#define _RF_PATCH_CPE_IEEE_802_15_4_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <string.h>

#ifndef CPE_PATCH_TYPE
#define CPE_PATCH_TYPE static const uint32_t
#endif

#ifndef SYS_PATCH_TYPE
#define SYS_PATCH_TYPE static const uint32_t
#endif

#ifndef PATCH_FUN_SPEC
#define PATCH_FUN_SPEC static inline
#endif

#ifndef _APPLY_PATCH_TAB
#define _APPLY_PATCH_TAB
#endif


CPE_PATCH_TYPE patchImageIeee802154[] = {
   0x21004039,
   0x210040cd,
   0x210040e1,
   0x210040fb,
   0x2100406d,
   0x6ac34807,
   0xf808f000,
   0x009b089b,
   0x6ac14804,
   0xd10007c9,
   0xbdf862c3,
   0xb5f84902,
   0x00004708,
   0x40045040,
   0x00029dd3,
   0x4801b510,
   0x00004700,
   0x000009df,
   0x49044803,
   0x05c068c0,
   0x47880fc0,
   0x47084902,
   0x21000340,
   0x000087d1,
   0x000053cd,
   0x480cb570,
   0x4c0c6ac0,
   0x0f800700,
   0x28012502,
   0x2803d008,
   0x6960d105,
   0x616043a8,
   0x15204907,
   0xbd706008,
   0x20014906,
   0x69604788,
   0x61604328,
   0x0000bd70,
   0x40046000,
   0x40041100,
   0xe000e180,
   0x00007d05,
   0x4c03b510,
   0xffc6f7ff,
   0x28006820,
   0xbd10d1fa,
   0x40041100,
   0x780a490b,
   0xd1042aff,
   0x7d924a0a,
   0x0f120712,
   0x4908700a,
   0x75883140,
   0x49054770,
   0x29ff7809,
   0x0900d005,
   0x43080100,
   0x31404902,
   0x47707588,
   0x210002a5,
   0x40086200,
};
#define _NWORD_PATCHIMAGE_IEEE_802_15_4 61

#define _NWORD_PATCHSYS_IEEE_802_15_4 0

#define _IRQ_PATCH_0 0x21004089


#ifndef _IEEE_802_15_4_SYSRAM_START
#define _IEEE_802_15_4_SYSRAM_START 0x20000000
#endif

#ifndef _IEEE_802_15_4_CPERAM_START
#define _IEEE_802_15_4_CPERAM_START 0x21000000
#endif

#define _IEEE_802_15_4_SYS_PATCH_FIXED_ADDR 0x20000000

#define _IEEE_802_15_4_PARSER_PATCH_TAB_OFFSET 0x0390
#define _IEEE_802_15_4_PATCH_TAB_OFFSET 0x0398
#define _IEEE_802_15_4_IRQPATCH_OFFSET 0x0434
#define _IEEE_802_15_4_PATCH_VEC_OFFSET 0x4024

#ifndef _IEEE_802_15_4_NO_PROG_STATE_VAR
static uint8_t bIeee802154PatchEntered = 0;
#endif

PATCH_FUN_SPEC void enterIeee802154CpePatch(void)
{
   uint32_t *pPatchVec = (uint32_t *) (_IEEE_802_15_4_CPERAM_START + _IEEE_802_15_4_PATCH_VEC_OFFSET);

#if (_NWORD_PATCHIMAGE_IEEE_802_15_4 > 0)
   memcpy(pPatchVec, patchImageIeee802154, sizeof(patchImageIeee802154));
#endif
}

PATCH_FUN_SPEC void enterIeee802154SysPatch(void)
{
}

PATCH_FUN_SPEC void configureIeee802154Patch(void)
{
   uint8_t *pPatchTab = (uint8_t *) (_IEEE_802_15_4_CPERAM_START + _IEEE_802_15_4_PATCH_TAB_OFFSET);
   uint32_t *pIrqPatch = (uint32_t *) (_IEEE_802_15_4_CPERAM_START + _IEEE_802_15_4_IRQPATCH_OFFSET);


   pPatchTab[53] = 0;
   pPatchTab[28] = 1;
   pPatchTab[105] = 2;
   pPatchTab[106] = 3;
   pPatchTab[70] = 4;

   pIrqPatch[21] = _IRQ_PATCH_0;
}

PATCH_FUN_SPEC void applyIeee802154Patch(void)
{
#ifdef _IEEE_802_15_4_NO_PROG_STATE_VAR
   enterIeee802154SysPatch();
   enterIeee802154CpePatch();
#else
   if (!bIeee802154PatchEntered)
   {
      enterIeee802154SysPatch();
      enterIeee802154CpePatch();
      bIeee802154PatchEntered = 1;
   }
#endif
   configureIeee802154Patch();
}

PATCH_FUN_SPEC void refreshIeee802154Patch(void)
{
   configureIeee802154Patch();
}

#ifndef _IEEE_802_15_4_NO_PROG_STATE_VAR
PATCH_FUN_SPEC void cleanIeee802154Patch(void)
{
   bIeee802154PatchEntered = 0;
}
#endif

PATCH_FUN_SPEC void rf_patch_cpe_ieee_802_15_4(void)
{
   applyIeee802154Patch();
}

#undef _IRQ_PATCH_0

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  _RF_PATCH_CPE_IEEE_802_15_4_H

