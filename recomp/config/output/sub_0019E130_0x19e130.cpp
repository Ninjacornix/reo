#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019E130
// Address: 0x19e130 - 0x19e440
void sub_0019E130_0x19e130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019E130_0x19e130");
#endif

    switch (ctx->pc) {
        case 0x19e17cu: goto label_19e17c;
        case 0x19e184u: goto label_19e184;
        default: break;
    }

    ctx->pc = 0x19e130u;

    // 0x19e130: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x19e130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x19e134: 0x3c0c0023  lui         $t4, 0x23
    ctx->pc = 0x19e134u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)35 << 16));
    // 0x19e138: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x19e138u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x19e13c: 0xc82d  daddu       $t9, $zero, $zero
    ctx->pc = 0x19e13cu;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e140: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x19e140u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x19e144: 0x258c0770  addiu       $t4, $t4, 0x770
    ctx->pc = 0x19e144u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 1904));
    // 0x19e148: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x19e148u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x19e14c: 0x240b0008  addiu       $t3, $zero, 0x8
    ctx->pc = 0x19e14cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x19e150: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x19e150u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x19e154: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x19e154u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x19e158: 0xa82d  daddu       $s5, $zero, $zero
    ctx->pc = 0x19e158u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e15c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19e15cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19e160: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19e160u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19e164: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19e164u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19e168: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19e168u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19e16c: 0x8c980010  lw          $t8, 0x10($a0)
    ctx->pc = 0x19e16cu;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x19e170: 0x8caf0010  lw          $t7, 0x10($a1)
    ctx->pc = 0x19e170u;
    SET_GPR_S32(ctx, 15, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x19e174: 0x100000a1  b           . + 4 + (0xA1 << 2)
    ctx->pc = 0x19E174u;
    {
        const bool branch_taken_0x19e174 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E174u;
            // 0x19e178: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e174) {
            ctx->pc = 0x19E3FCu;
            goto label_19e3fc;
        }
    }
    ctx->pc = 0x19E17Cu;
label_19e17c:
    // 0x19e17c: 0x1000009a  b           . + 4 + (0x9A << 2)
    ctx->pc = 0x19E17Cu;
    {
        const bool branch_taken_0x19e17c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E17Cu;
            // 0x19e180: 0xb02d  daddu       $s6, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e17c) {
            ctx->pc = 0x19E3E8u;
            goto label_19e3e8;
        }
    }
    ctx->pc = 0x19E184u;
label_19e184:
    // 0x19e184: 0x14e3000c  bne         $a3, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x19E184u;
    {
        const bool branch_taken_0x19e184 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 3));
        if (branch_taken_0x19e184) {
            ctx->pc = 0x19E1B8u;
            goto label_19e1b8;
        }
    }
    ctx->pc = 0x19E18Cu;
    // 0x19e18c: 0x14c3000a  bne         $a2, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x19E18Cu;
    {
        const bool branch_taken_0x19e18c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 3));
        if (branch_taken_0x19e18c) {
            ctx->pc = 0x19E1B8u;
            goto label_19e1b8;
        }
    }
    ctx->pc = 0x19E194u;
    // 0x19e194: 0x3203001f  andi        $v1, $s0, 0x1F
    ctx->pc = 0x19e194u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)31);
    // 0x19e198: 0x8c8d0014  lw          $t5, 0x14($a0)
    ctx->pc = 0x19e198u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x19e19c: 0x1834021  addu        $t0, $t4, $v1
    ctx->pc = 0x19e19cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 3)));
    // 0x19e1a0: 0x91080000  lbu         $t0, 0x0($t0)
    ctx->pc = 0x19e1a0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x19e1a4: 0x320300e0  andi        $v1, $s0, 0xE0
    ctx->pc = 0x19e1a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)224);
    // 0x19e1a8: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x19e1a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19e1ac: 0x1a31818  mult        $v1, $t5, $v1
    ctx->pc = 0x19e1acu;
    { int64_t result = (int64_t)GPR_S32(ctx, 13) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x19e1b0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x19E1B0u;
    {
        const bool branch_taken_0x19e1b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E1B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E1B0u;
            // 0x19e1b4: 0x3034821  addu        $t1, $t8, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e1b0) {
            ctx->pc = 0x19E1C4u;
            goto label_19e1c4;
        }
    }
    ctx->pc = 0x19E1B8u;
label_19e1b8:
    // 0x19e1b8: 0x8c8d0014  lw          $t5, 0x14($a0)
    ctx->pc = 0x19e1b8u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x19e1bc: 0x3194821  addu        $t1, $t8, $t9
    ctx->pc = 0x19e1bcu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 25)));
    // 0x19e1c0: 0x32dc821  addu        $t9, $t9, $t5
    ctx->pc = 0x19e1c0u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 25), GPR_U32(ctx, 13)));
label_19e1c4:
    // 0x19e1c4: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x19e1c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x19e1c8: 0x11a30012  beq         $t5, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x19E1C8u;
    {
        const bool branch_taken_0x19e1c8 = (GPR_U64(ctx, 13) == GPR_U64(ctx, 3));
        ctx->pc = 0x19E1CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E1C8u;
            // 0x19e1cc: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e1c8) {
            ctx->pc = 0x19E214u;
            goto label_19e214;
        }
    }
    ctx->pc = 0x19E1D0u;
    // 0x19e1d0: 0x11a30008  beq         $t5, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x19E1D0u;
    {
        const bool branch_taken_0x19e1d0 = (GPR_U64(ctx, 13) == GPR_U64(ctx, 3));
        if (branch_taken_0x19e1d0) {
            ctx->pc = 0x19E1F4u;
            goto label_19e1f4;
        }
    }
    ctx->pc = 0x19E1D8u;
    // 0x19e1d8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x19e1d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x19e1dc: 0x11a30003  beq         $t5, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E1DCu;
    {
        const bool branch_taken_0x19e1dc = (GPR_U64(ctx, 13) == GPR_U64(ctx, 3));
        if (branch_taken_0x19e1dc) {
            ctx->pc = 0x19E1ECu;
            goto label_19e1ec;
        }
    }
    ctx->pc = 0x19E1E4u;
    // 0x19e1e4: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x19E1E4u;
    {
        const bool branch_taken_0x19e1e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E1E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E1E4u;
            // 0x19e1e8: 0x8c83001c  lw          $v1, 0x1C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e1e4) {
            ctx->pc = 0x19E21Cu;
            goto label_19e21c;
        }
    }
    ctx->pc = 0x19E1ECu;
label_19e1ec:
    // 0x19e1ec: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x19E1ECu;
    {
        const bool branch_taken_0x19e1ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E1F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E1ECu;
            // 0x19e1f0: 0x95220000  lhu         $v0, 0x0($t1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e1ec) {
            ctx->pc = 0x19E218u;
            goto label_19e218;
        }
    }
    ctx->pc = 0x19E1F4u;
label_19e1f4:
    // 0x19e1f4: 0x91280002  lbu         $t0, 0x2($t1)
    ctx->pc = 0x19e1f4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 2)));
    // 0x19e1f8: 0x91230001  lbu         $v1, 0x1($t1)
    ctx->pc = 0x19e1f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 1)));
    // 0x19e1fc: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x19e1fcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x19e200: 0x84400  sll         $t0, $t0, 16
    ctx->pc = 0x19e200u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 16));
    // 0x19e204: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x19e204u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x19e208: 0x1031825  or          $v1, $t0, $v1
    ctx->pc = 0x19e208u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x19e20c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x19E20Cu;
    {
        const bool branch_taken_0x19e20c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E20Cu;
            // 0x19e210: 0x431025  or          $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e20c) {
            ctx->pc = 0x19E218u;
            goto label_19e218;
        }
    }
    ctx->pc = 0x19E214u;
label_19e214:
    // 0x19e214: 0x8d220000  lw          $v0, 0x0($t1)
    ctx->pc = 0x19e214u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
label_19e218:
    // 0x19e218: 0x8c83001c  lw          $v1, 0x1C($a0)
    ctx->pc = 0x19e218u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
label_19e21c:
    // 0x19e21c: 0x8c8a0018  lw          $t2, 0x18($a0)
    ctx->pc = 0x19e21cu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x19e220: 0x8c930020  lw          $s3, 0x20($a0)
    ctx->pc = 0x19e220u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x19e224: 0x8c890028  lw          $t1, 0x28($a0)
    ctx->pc = 0x19e224u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x19e228: 0x8c880024  lw          $t0, 0x24($a0)
    ctx->pc = 0x19e228u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x19e22c: 0x8c92002c  lw          $s2, 0x2C($a0)
    ctx->pc = 0x19e22cu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x19e230: 0x627006  srlv        $t6, $v0, $v1
    ctx->pc = 0x19e230u;
    SET_GPR_S32(ctx, 14, (int32_t)SRL32(GPR_U32(ctx, 2), GPR_U32(ctx, 3) & 0x1F));
    // 0x19e234: 0x8c910038  lw          $s1, 0x38($a0)
    ctx->pc = 0x19e234u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 56)));
    // 0x19e238: 0x8c830034  lw          $v1, 0x34($a0)
    ctx->pc = 0x19e238u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 52)));
    // 0x19e23c: 0x16a5023  subu        $t2, $t3, $t2
    ctx->pc = 0x19e23cu;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 10)));
    // 0x19e240: 0x26e7024  and         $t6, $s3, $t6
    ctx->pc = 0x19e240u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 19) & GPR_U64(ctx, 14));
    // 0x19e244: 0x14ea004  sllv        $s4, $t6, $t2
    ctx->pc = 0x19e244u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 14), GPR_U32(ctx, 10) & 0x1F));
    // 0x19e248: 0x1227006  srlv        $t6, $v0, $t1
    ctx->pc = 0x19e248u;
    SET_GPR_S32(ctx, 14, (int32_t)SRL32(GPR_U32(ctx, 2), GPR_U32(ctx, 9) & 0x1F));
    // 0x19e24c: 0x1684023  subu        $t0, $t3, $t0
    ctx->pc = 0x19e24cu;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 8)));
    // 0x19e250: 0x24e7024  and         $t6, $s2, $t6
    ctx->pc = 0x19e250u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 18) & GPR_U64(ctx, 14));
    // 0x19e254: 0x8c8a0030  lw          $t2, 0x30($a0)
    ctx->pc = 0x19e254u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x19e258: 0x10e9804  sllv        $s3, $t6, $t0
    ctx->pc = 0x19e258u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 14), GPR_U32(ctx, 8) & 0x1F));
    // 0x19e25c: 0x8c890044  lw          $t1, 0x44($a0)
    ctx->pc = 0x19e25cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x19e260: 0x627006  srlv        $t6, $v0, $v1
    ctx->pc = 0x19e260u;
    SET_GPR_S32(ctx, 14, (int32_t)SRL32(GPR_U32(ctx, 2), GPR_U32(ctx, 3) & 0x1F));
    // 0x19e264: 0x8c880040  lw          $t0, 0x40($a0)
    ctx->pc = 0x19e264u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x19e268: 0x8c83003c  lw          $v1, 0x3C($a0)
    ctx->pc = 0x19e268u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x19e26c: 0x22e7024  and         $t6, $s1, $t6
    ctx->pc = 0x19e26cu;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 17) & GPR_U64(ctx, 14));
    // 0x19e270: 0x16a5023  subu        $t2, $t3, $t2
    ctx->pc = 0x19e270u;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 10)));
    // 0x19e274: 0x1021006  srlv        $v0, $v0, $t0
    ctx->pc = 0x19e274u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), GPR_U32(ctx, 8) & 0x1F));
    // 0x19e278: 0x1224024  and         $t0, $t1, $v0
    ctx->pc = 0x19e278u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 9) & GPR_U64(ctx, 2));
    // 0x19e27c: 0x1631023  subu        $v0, $t3, $v1
    ctx->pc = 0x19e27cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x19e280: 0x488804  sllv        $s1, $t0, $v0
    ctx->pc = 0x19e280u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x19e284: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19e284u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19e288: 0x14e2000b  bne         $a3, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x19E288u;
    {
        const bool branch_taken_0x19e288 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x19E28Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E288u;
            // 0x19e28c: 0x14e9004  sllv        $s2, $t6, $t2 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 14), GPR_U32(ctx, 10) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e288) {
            ctx->pc = 0x19E2B8u;
            goto label_19e2b8;
        }
    }
    ctx->pc = 0x19E290u;
    // 0x19e290: 0x14c00009  bnez        $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x19E290u;
    {
        const bool branch_taken_0x19e290 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E290u;
            // 0x19e294: 0x3202001f  andi        $v0, $s0, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e290) {
            ctx->pc = 0x19E2B8u;
            goto label_19e2b8;
        }
    }
    ctx->pc = 0x19E298u;
    // 0x19e298: 0x320300e0  andi        $v1, $s0, 0xE0
    ctx->pc = 0x19e298u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)224);
    // 0x19e29c: 0x1824021  addu        $t0, $t4, $v0
    ctx->pc = 0x19e29cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 2)));
    // 0x19e2a0: 0x91080000  lbu         $t0, 0x0($t0)
    ctx->pc = 0x19e2a0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x19e2a4: 0x8ca20014  lw          $v0, 0x14($a1)
    ctx->pc = 0x19e2a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x19e2a8: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x19e2a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19e2ac: 0x431018  mult        $v0, $v0, $v1
    ctx->pc = 0x19e2acu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x19e2b0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x19E2B0u;
    {
        const bool branch_taken_0x19e2b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E2B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E2B0u;
            // 0x19e2b4: 0x1e27021  addu        $t6, $t7, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 15), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e2b0) {
            ctx->pc = 0x19E2D0u;
            goto label_19e2d0;
        }
    }
    ctx->pc = 0x19E2B8u;
label_19e2b8:
    // 0x19e2b8: 0x8ca3000c  lw          $v1, 0xC($a1)
    ctx->pc = 0x19e2b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x19e2bc: 0x8ca20014  lw          $v0, 0x14($a1)
    ctx->pc = 0x19e2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x19e2c0: 0x751818  mult        $v1, $v1, $s5
    ctx->pc = 0x19e2c0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 21); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x19e2c4: 0x70561018  mult1       $v0, $v0, $s6
    ctx->pc = 0x19e2c4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 22); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x19e2c8: 0x1e31821  addu        $v1, $t7, $v1
    ctx->pc = 0x19e2c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 15), GPR_U32(ctx, 3)));
    // 0x19e2cc: 0x627021  addu        $t6, $v1, $v0
    ctx->pc = 0x19e2ccu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_19e2d0:
    // 0x19e2d0: 0x14c00008  bnez        $a2, . + 4 + (0x8 << 2)
    ctx->pc = 0x19E2D0u;
    {
        const bool branch_taken_0x19e2d0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E2D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E2D0u;
            // 0x19e2d4: 0x24020080  addiu       $v0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e2d0) {
            ctx->pc = 0x19E2F4u;
            goto label_19e2f4;
        }
    }
    ctx->pc = 0x19E2D8u;
    // 0x19e2d8: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x19e2d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x19e2dc: 0x16220003  bne         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E2DCu;
    {
        const bool branch_taken_0x19e2dc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x19e2dc) {
            ctx->pc = 0x19E2ECu;
            goto label_19e2ec;
        }
    }
    ctx->pc = 0x19E2E4u;
    // 0x19e2e4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x19E2E4u;
    {
        const bool branch_taken_0x19e2e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E2E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E2E4u;
            // 0x19e2e8: 0x24110080  addiu       $s1, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e2e4) {
            ctx->pc = 0x19E308u;
            goto label_19e308;
        }
    }
    ctx->pc = 0x19E2ECu;
label_19e2ec:
    // 0x19e2ec: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x19E2ECu;
    {
        const bool branch_taken_0x19e2ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E2F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E2ECu;
            // 0x19e2f0: 0x118842  srl         $s1, $s1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e2ec) {
            ctx->pc = 0x19E308u;
            goto label_19e308;
        }
    }
    ctx->pc = 0x19E2F4u;
label_19e2f4:
    // 0x19e2f4: 0x16220003  bne         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E2F4u;
    {
        const bool branch_taken_0x19e2f4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x19e2f4) {
            ctx->pc = 0x19E304u;
            goto label_19e304;
        }
    }
    ctx->pc = 0x19E2FCu;
    // 0x19e2fc: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x19E2FCu;
    {
        const bool branch_taken_0x19e2fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E2FCu;
            // 0x19e300: 0x241100ff  addiu       $s1, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e2fc) {
            ctx->pc = 0x19E308u;
            goto label_19e308;
        }
    }
    ctx->pc = 0x19E304u;
label_19e304:
    // 0x19e304: 0x118840  sll         $s1, $s1, 1
    ctx->pc = 0x19e304u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
label_19e308:
    // 0x19e308: 0x8ca30024  lw          $v1, 0x24($a1)
    ctx->pc = 0x19e308u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 36)));
    // 0x19e30c: 0x8caa0018  lw          $t2, 0x18($a1)
    ctx->pc = 0x19e30cu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x19e310: 0x8ca90020  lw          $t1, 0x20($a1)
    ctx->pc = 0x19e310u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x19e314: 0x8ca8001c  lw          $t0, 0x1C($a1)
    ctx->pc = 0x19e314u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x19e318: 0x8cb7002c  lw          $s7, 0x2C($a1)
    ctx->pc = 0x19e318u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 44)));
    // 0x19e31c: 0x8ca20028  lw          $v0, 0x28($a1)
    ctx->pc = 0x19e31cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x19e320: 0x1631823  subu        $v1, $t3, $v1
    ctx->pc = 0x19e320u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x19e324: 0x731806  srlv        $v1, $s3, $v1
    ctx->pc = 0x19e324u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 19), GPR_U32(ctx, 3) & 0x1F));
    // 0x19e328: 0x7fa200a0  sq          $v0, 0xA0($sp)
    ctx->pc = 0x19e328u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 160), GPR_VEC(ctx, 2));
    // 0x19e32c: 0x16a1023  subu        $v0, $t3, $t2
    ctx->pc = 0x19e32cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 10)));
    // 0x19e330: 0x8cbe0030  lw          $fp, 0x30($a1)
    ctx->pc = 0x19e330u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 48)));
    // 0x19e334: 0x545006  srlv        $t2, $s4, $v0
    ctx->pc = 0x19e334u;
    SET_GPR_S32(ctx, 10, (int32_t)SRL32(GPR_U32(ctx, 20), GPR_U32(ctx, 2) & 0x1F));
    // 0x19e338: 0x8ca20038  lw          $v0, 0x38($a1)
    ctx->pc = 0x19e338u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 56)));
    // 0x19e33c: 0x12a4824  and         $t1, $t1, $t2
    ctx->pc = 0x19e33cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) & GPR_U64(ctx, 10));
    // 0x19e340: 0x2e35024  and         $t2, $s7, $v1
    ctx->pc = 0x19e340u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 23) & GPR_U64(ctx, 3));
    // 0x19e344: 0x7fa200b0  sq          $v0, 0xB0($sp)
    ctx->pc = 0x19e344u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 176), GPR_VEC(ctx, 2));
    // 0x19e348: 0x8ca20034  lw          $v0, 0x34($a1)
    ctx->pc = 0x19e348u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 52)));
    // 0x19e34c: 0x7fa20090  sq          $v0, 0x90($sp)
    ctx->pc = 0x19e34cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 144), GPR_VEC(ctx, 2));
    // 0x19e350: 0x1091004  sllv        $v0, $t1, $t0
    ctx->pc = 0x19e350u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 8) & 0x1F));
    // 0x19e354: 0x8ca30044  lw          $v1, 0x44($a1)
    ctx->pc = 0x19e354u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 68)));
    // 0x19e358: 0x7ba900a0  lq          $t1, 0xA0($sp)
    ctx->pc = 0x19e358u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x19e35c: 0x8ca8003c  lw          $t0, 0x3C($a1)
    ctx->pc = 0x19e35cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 60)));
    // 0x19e360: 0x8cb70040  lw          $s7, 0x40($a1)
    ctx->pc = 0x19e360u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 64)));
    // 0x19e364: 0x12a5004  sllv        $t2, $t2, $t1
    ctx->pc = 0x19e364u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 9) & 0x1F));
    // 0x19e368: 0x4a5025  or          $t2, $v0, $t2
    ctx->pc = 0x19e368u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 2) | GPR_U64(ctx, 10));
    // 0x19e36c: 0x17e4823  subu        $t1, $t3, $fp
    ctx->pc = 0x19e36cu;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 30)));
    // 0x19e370: 0x7ba200b0  lq          $v0, 0xB0($sp)
    ctx->pc = 0x19e370u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x19e374: 0x1324806  srlv        $t1, $s2, $t1
    ctx->pc = 0x19e374u;
    SET_GPR_S32(ctx, 9, (int32_t)SRL32(GPR_U32(ctx, 18), GPR_U32(ctx, 9) & 0x1F));
    // 0x19e378: 0x1684023  subu        $t0, $t3, $t0
    ctx->pc = 0x19e378u;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 8)));
    // 0x19e37c: 0x1114006  srlv        $t0, $s1, $t0
    ctx->pc = 0x19e37cu;
    SET_GPR_S32(ctx, 8, (int32_t)SRL32(GPR_U32(ctx, 17), GPR_U32(ctx, 8) & 0x1F));
    // 0x19e380: 0x681824  and         $v1, $v1, $t0
    ctx->pc = 0x19e380u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 8));
    // 0x19e384: 0x2e31804  sllv        $v1, $v1, $s7
    ctx->pc = 0x19e384u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 23) & 0x1F));
    // 0x19e388: 0x494824  and         $t1, $v0, $t1
    ctx->pc = 0x19e388u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) & GPR_U64(ctx, 9));
    // 0x19e38c: 0x7ba20090  lq          $v0, 0x90($sp)
    ctx->pc = 0x19e38cu;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x19e390: 0x491004  sllv        $v0, $t1, $v0
    ctx->pc = 0x19e390u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 2) & 0x1F));
    // 0x19e394: 0x4a1025  or          $v0, $v0, $t2
    ctx->pc = 0x19e394u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 10));
    // 0x19e398: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x19e398u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x19e39c: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x19e39cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x19e3a0: 0x11a3000e  beq         $t5, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x19E3A0u;
    {
        const bool branch_taken_0x19e3a0 = (GPR_U64(ctx, 13) == GPR_U64(ctx, 3));
        ctx->pc = 0x19E3A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E3A0u;
            // 0x19e3a4: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e3a0) {
            ctx->pc = 0x19E3DCu;
            goto label_19e3dc;
        }
    }
    ctx->pc = 0x19E3A8u;
    // 0x19e3a8: 0x11a30008  beq         $t5, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x19E3A8u;
    {
        const bool branch_taken_0x19e3a8 = (GPR_U64(ctx, 13) == GPR_U64(ctx, 3));
        if (branch_taken_0x19e3a8) {
            ctx->pc = 0x19E3CCu;
            goto label_19e3cc;
        }
    }
    ctx->pc = 0x19E3B0u;
    // 0x19e3b0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x19e3b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x19e3b4: 0x11a30003  beq         $t5, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E3B4u;
    {
        const bool branch_taken_0x19e3b4 = (GPR_U64(ctx, 13) == GPR_U64(ctx, 3));
        if (branch_taken_0x19e3b4) {
            ctx->pc = 0x19E3C4u;
            goto label_19e3c4;
        }
    }
    ctx->pc = 0x19E3BCu;
    // 0x19e3bc: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x19E3BCu;
    {
        const bool branch_taken_0x19e3bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E3C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E3BCu;
            // 0x19e3c0: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e3bc) {
            ctx->pc = 0x19E3E4u;
            goto label_19e3e4;
        }
    }
    ctx->pc = 0x19E3C4u;
label_19e3c4:
    // 0x19e3c4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x19E3C4u;
    {
        const bool branch_taken_0x19e3c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E3C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E3C4u;
            // 0x19e3c8: 0xa5c20000  sh          $v0, 0x0($t6) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 14), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e3c4) {
            ctx->pc = 0x19E3E0u;
            goto label_19e3e0;
        }
    }
    ctx->pc = 0x19E3CCu;
label_19e3cc:
    // 0x19e3cc: 0xa1d40000  sb          $s4, 0x0($t6)
    ctx->pc = 0x19e3ccu;
    WRITE8(ADD32(GPR_U32(ctx, 14), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x19e3d0: 0xa1d30001  sb          $s3, 0x1($t6)
    ctx->pc = 0x19e3d0u;
    WRITE8(ADD32(GPR_U32(ctx, 14), 1), (uint8_t)GPR_U32(ctx, 19));
    // 0x19e3d4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x19E3D4u;
    {
        const bool branch_taken_0x19e3d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E3D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E3D4u;
            // 0x19e3d8: 0xa1d20002  sb          $s2, 0x2($t6) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 14), 2), (uint8_t)GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e3d4) {
            ctx->pc = 0x19E3E0u;
            goto label_19e3e0;
        }
    }
    ctx->pc = 0x19E3DCu;
label_19e3dc:
    // 0x19e3dc: 0xadc20000  sw          $v0, 0x0($t6)
    ctx->pc = 0x19e3dcu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 0), GPR_U32(ctx, 2));
label_19e3e0:
    // 0x19e3e0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x19e3e0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_19e3e4:
    // 0x19e3e4: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x19e3e4u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
label_19e3e8:
    // 0x19e3e8: 0x8ca30004  lw          $v1, 0x4($a1)
    ctx->pc = 0x19e3e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x19e3ec: 0x2c3182a  slt         $v1, $s6, $v1
    ctx->pc = 0x19e3ecu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 22) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x19e3f0: 0x1460ff64  bnez        $v1, . + 4 + (-0x9C << 2)
    ctx->pc = 0x19E3F0u;
    {
        const bool branch_taken_0x19e3f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E3F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E3F0u;
            // 0x19e3f4: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e3f0) {
            ctx->pc = 0x19E184u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e184;
        }
    }
    ctx->pc = 0x19E3F8u;
    // 0x19e3f8: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x19e3f8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
label_19e3fc:
    // 0x19e3fc: 0x8ca30008  lw          $v1, 0x8($a1)
    ctx->pc = 0x19e3fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x19e400: 0x2a3182a  slt         $v1, $s5, $v1
    ctx->pc = 0x19e400u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x19e404: 0x1460ff5d  bnez        $v1, . + 4 + (-0xA3 << 2)
    ctx->pc = 0x19E404u;
    {
        const bool branch_taken_0x19e404 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19e404) {
            ctx->pc = 0x19E17Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e17c;
        }
    }
    ctx->pc = 0x19E40Cu;
    // 0x19e40c: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x19e40cu;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x19e410: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19e410u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19e414: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x19e414u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x19e418: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x19e418u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x19e41c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x19e41cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x19e420: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x19e420u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19e424: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19e424u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19e428: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19e428u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19e42c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19e42cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19e430: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19e430u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19e434: 0x3e00008  jr          $ra
    ctx->pc = 0x19E434u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19E438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E434u;
            // 0x19e438: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19E17Cu: goto label_19e17c;
            case 0x19E184u: goto label_19e184;
            case 0x19E1B8u: goto label_19e1b8;
            case 0x19E1C4u: goto label_19e1c4;
            case 0x19E1ECu: goto label_19e1ec;
            case 0x19E1F4u: goto label_19e1f4;
            case 0x19E214u: goto label_19e214;
            case 0x19E218u: goto label_19e218;
            case 0x19E21Cu: goto label_19e21c;
            case 0x19E2B8u: goto label_19e2b8;
            case 0x19E2D0u: goto label_19e2d0;
            case 0x19E2ECu: goto label_19e2ec;
            case 0x19E2F4u: goto label_19e2f4;
            case 0x19E304u: goto label_19e304;
            case 0x19E308u: goto label_19e308;
            case 0x19E3C4u: goto label_19e3c4;
            case 0x19E3CCu: goto label_19e3cc;
            case 0x19E3DCu: goto label_19e3dc;
            case 0x19E3E0u: goto label_19e3e0;
            case 0x19E3E4u: goto label_19e3e4;
            case 0x19E3E8u: goto label_19e3e8;
            case 0x19E3FCu: goto label_19e3fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19E43Cu;
    // 0x19e43c: 0x0  nop
    ctx->pc = 0x19e43cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
