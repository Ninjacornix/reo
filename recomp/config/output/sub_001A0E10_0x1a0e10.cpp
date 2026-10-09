#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A0E10
// Address: 0x1a0e10 - 0x1a13f0
void sub_001A0E10_0x1a0e10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A0E10_0x1a0e10");
#endif

    switch (ctx->pc) {
        case 0x1a0e48u: goto label_1a0e48;
        case 0x1a0e78u: goto label_1a0e78;
        case 0x1a0f48u: goto label_1a0f48;
        case 0x1a0facu: goto label_1a0fac;
        case 0x1a0fdcu: goto label_1a0fdc;
        case 0x1a0ffcu: goto label_1a0ffc;
        case 0x1a1088u: goto label_1a1088;
        case 0x1a1124u: goto label_1a1124;
        case 0x1a112cu: goto label_1a112c;
        case 0x1a11bcu: goto label_1a11bc;
        case 0x1a1240u: goto label_1a1240;
        case 0x1a1254u: goto label_1a1254;
        case 0x1a12a0u: goto label_1a12a0;
        case 0x1a12b4u: goto label_1a12b4;
        case 0x1a12d4u: goto label_1a12d4;
        case 0x1a13dcu: goto label_1a13dc;
        default: break;
    }

    ctx->pc = 0x1a0e10u;

label_1a0e10:
    // 0x1a0e10: 0x8068388  j           func_1A0E20
    ctx->pc = 0x1A0E10u;
    ctx->pc = 0x1A0E14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0E10u;
            // 0x1a0e14: 0x8c860018  lw          $a2, 0x18($a0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0E20u;
    goto label_1a0e20;
    ctx->pc = 0x1A0E18u;
    // 0x1a0e18: 0x0  nop
    ctx->pc = 0x1a0e18u;
    // NOP
    // 0x1a0e1c: 0x0  nop
    ctx->pc = 0x1a0e1cu;
    // NOP
label_1a0e20:
    // 0x1a0e20: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1a0e20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1a0e24: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1a0e24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1a0e28: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a0e28u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a0e2c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a0e2cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a0e30: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1a0e30u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0e34: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a0e34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a0e38: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1a0e38u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0e3c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1a0e3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0e40: 0xc06856c  jal         func_1A15B0
    ctx->pc = 0x1A0E40u;
    SET_GPR_U32(ctx, 31, 0x1A0E48u);
    ctx->pc = 0x1A0E44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0E40u;
            // 0x1a0e44: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A15B0u;
    if (runtime->hasFunction(0x1A15B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A15B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0E48u; }
        if (ctx->pc != 0x1A0E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A15B0_0x1a15b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0E48u; }
        if (ctx->pc != 0x1A0E48u) { return; }
    }
    ctx->pc = 0x1A0E48u;
label_1a0e48:
    // 0x1a0e48: 0x2511821  addu        $v1, $s2, $s1
    ctx->pc = 0x1a0e48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
    // 0x1a0e4c: 0x62082b  sltu        $at, $v1, $v0
    ctx->pc = 0x1a0e4cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1a0e50: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A0E50u;
    {
        const bool branch_taken_0x1a0e50 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a0e50) {
            ctx->pc = 0x1A0E60u;
            goto label_1a0e60;
        }
    }
    ctx->pc = 0x1A0E58u;
    // 0x1a0e58: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1A0E58u;
    {
        const bool branch_taken_0x1a0e58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0E5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0E58u;
            // 0x1a0e5c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0e58) {
            ctx->pc = 0x1A0F4Cu;
            goto label_1a0f4c;
        }
    }
    ctx->pc = 0x1A0E60u;
label_1a0e60:
    // 0x1a0e60: 0x16400003  bnez        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A0E60u;
    {
        const bool branch_taken_0x1a0e60 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A0E64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0E60u;
            // 0x1a0e64: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0e60) {
            ctx->pc = 0x1A0E70u;
            goto label_1a0e70;
        }
    }
    ctx->pc = 0x1A0E68u;
    // 0x1a0e68: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x1A0E68u;
    {
        const bool branch_taken_0x1a0e68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0E68u;
            // 0x1a0e6c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0e68) {
            ctx->pc = 0x1A0F4Cu;
            goto label_1a0f4c;
        }
    }
    ctx->pc = 0x1A0E70u;
label_1a0e70:
    // 0x1a0e70: 0xc068580  jal         func_1A1600
    ctx->pc = 0x1A0E70u;
    SET_GPR_U32(ctx, 31, 0x1A0E78u);
    ctx->pc = 0x1A1600u;
    if (runtime->hasFunction(0x1A1600u)) {
        auto targetFn = runtime->lookupFunction(0x1A1600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0E78u; }
        if (ctx->pc != 0x1A0E78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1600_0x1a1600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0E78u; }
        if (ctx->pc != 0x1A0E78u) { return; }
    }
    ctx->pc = 0x1A0E78u;
label_1a0e78:
    // 0x1a0e78: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1a0e78u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0e7c: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1a0e7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1a0e80: 0x16020003  bne         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A0E80u;
    {
        const bool branch_taken_0x1a0e80 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x1a0e80) {
            ctx->pc = 0x1A0E90u;
            goto label_1a0e90;
        }
    }
    ctx->pc = 0x1A0E88u;
    // 0x1a0e88: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1A0E88u;
    {
        const bool branch_taken_0x1a0e88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0E88u;
            // 0x1a0e8c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0e88) {
            ctx->pc = 0x1A0F4Cu;
            goto label_1a0f4c;
        }
    }
    ctx->pc = 0x1A0E90u;
label_1a0e90:
    // 0x1a0e90: 0x8e630008  lw          $v1, 0x8($s3)
    ctx->pc = 0x1a0e90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a0e94: 0x101100  sll         $v0, $s0, 4
    ctx->pc = 0x1a0e94u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x1a0e98: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1a0e98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a0e9c: 0xa460000a  sh          $zero, 0xA($v1)
    ctx->pc = 0x1a0e9cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a0ea0: 0x8e630008  lw          $v1, 0x8($s3)
    ctx->pc = 0x1a0ea0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a0ea4: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1a0ea4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a0ea8: 0xac720004  sw          $s2, 0x4($v1)
    ctx->pc = 0x1a0ea8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 18));
    // 0x1a0eac: 0x8e630008  lw          $v1, 0x8($s3)
    ctx->pc = 0x1a0eacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a0eb0: 0x8e640018  lw          $a0, 0x18($s3)
    ctx->pc = 0x1a0eb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a0eb4: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1a0eb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a0eb8: 0xa4640008  sh          $a0, 0x8($v1)
    ctx->pc = 0x1a0eb8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 8), (uint16_t)GPR_U32(ctx, 4));
    // 0x1a0ebc: 0x8e63000c  lw          $v1, 0xC($s3)
    ctx->pc = 0x1a0ebcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x1a0ec0: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1A0EC0u;
    {
        const bool branch_taken_0x1a0ec0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0EC0u;
            // 0x1a0ec4: 0x2623ffff  addiu       $v1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0ec0) {
            ctx->pc = 0x1A0F04u;
            goto label_1a0f04;
        }
    }
    ctx->pc = 0x1A0EC8u;
    // 0x1a0ec8: 0x8e640008  lw          $a0, 0x8($s3)
    ctx->pc = 0x1a0ec8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a0ecc: 0x2623ffff  addiu       $v1, $s1, -0x1
    ctx->pc = 0x1a0eccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x1a0ed0: 0x8e650010  lw          $a1, 0x10($s3)
    ctx->pc = 0x1a0ed0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1a0ed4: 0x601827  not         $v1, $v1
    ctx->pc = 0x1a0ed4u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1a0ed8: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a0ed8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1a0edc: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x1a0edcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x1a0ee0: 0x8e640008  lw          $a0, 0x8($s3)
    ctx->pc = 0x1a0ee0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a0ee4: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x1a0ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1a0ee8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1a0ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a0eec: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1a0eecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1a0ef0: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x1a0ef0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1a0ef4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1a0ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1a0ef8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1a0ef8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1a0efc: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A0EFCu;
    {
        const bool branch_taken_0x1a0efc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0F00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0EFCu;
            // 0x1a0f00: 0xae620010  sw          $v0, 0x10($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0efc) {
            ctx->pc = 0x1A0F30u;
            goto label_1a0f30;
        }
    }
    ctx->pc = 0x1A0F04u;
label_1a0f04:
    // 0x1a0f04: 0x8e640010  lw          $a0, 0x10($s3)
    ctx->pc = 0x1a0f04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1a0f08: 0x602827  not         $a1, $v1
    ctx->pc = 0x1a0f08u;
    SET_GPR_U64(ctx, 5, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1a0f0c: 0x8e630008  lw          $v1, 0x8($s3)
    ctx->pc = 0x1a0f0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a0f10: 0x922023  subu        $a0, $a0, $s2
    ctx->pc = 0x1a0f10u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x1a0f14: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x1a0f14u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x1a0f18: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1a0f18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a0f1c: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1a0f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x1a0f20: 0x8e630008  lw          $v1, 0x8($s3)
    ctx->pc = 0x1a0f20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a0f24: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a0f24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a0f28: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1a0f28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a0f2c: 0xae620010  sw          $v0, 0x10($s3)
    ctx->pc = 0x1a0f2cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
label_1a0f30:
    // 0x1a0f30: 0x8e62001c  lw          $v0, 0x1C($s3)
    ctx->pc = 0x1a0f30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1a0f34: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a0f34u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0f38: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1a0f38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0f3c: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1a0f3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1a0f40: 0xc06859c  jal         func_1A1670
    ctx->pc = 0x1A0F40u;
    SET_GPR_U32(ctx, 31, 0x1A0F48u);
    ctx->pc = 0x1A0F44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0F40u;
            // 0x1a0f44: 0xae62001c  sw          $v0, 0x1C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1670u;
    if (runtime->hasFunction(0x1A1670u)) {
        auto targetFn = runtime->lookupFunction(0x1A1670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0F48u; }
        if (ctx->pc != 0x1A0F48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1670_0x1a1670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0F48u; }
        if (ctx->pc != 0x1A0F48u) { return; }
    }
    ctx->pc = 0x1A0F48u;
label_1a0f48:
    // 0x1a0f48: 0x26020001  addiu       $v0, $s0, 0x1
    ctx->pc = 0x1a0f48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1a0f4c:
    // 0x1a0f4c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1a0f4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a0f50: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a0f50u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a0f54: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a0f54u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a0f58: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a0f58u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a0f5c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a0f5cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a0f60: 0x3e00008  jr          $ra
    ctx->pc = 0x1A0F60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A0F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0F60u;
            // 0x1a0f64: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A0E10u: goto label_1a0e10;
            case 0x1A0E20u: goto label_1a0e20;
            case 0x1A0E48u: goto label_1a0e48;
            case 0x1A0E60u: goto label_1a0e60;
            case 0x1A0E70u: goto label_1a0e70;
            case 0x1A0E78u: goto label_1a0e78;
            case 0x1A0E90u: goto label_1a0e90;
            case 0x1A0F04u: goto label_1a0f04;
            case 0x1A0F30u: goto label_1a0f30;
            case 0x1A0F48u: goto label_1a0f48;
            case 0x1A0F4Cu: goto label_1a0f4c;
            case 0x1A0FACu: goto label_1a0fac;
            case 0x1A0FC4u: goto label_1a0fc4;
            case 0x1A0FDCu: goto label_1a0fdc;
            case 0x1A0FE4u: goto label_1a0fe4;
            case 0x1A0FFCu: goto label_1a0ffc;
            case 0x1A1088u: goto label_1a1088;
            case 0x1A1090u: goto label_1a1090;
            case 0x1A1098u: goto label_1a1098;
            case 0x1A1124u: goto label_1a1124;
            case 0x1A112Cu: goto label_1a112c;
            case 0x1A11BCu: goto label_1a11bc;
            case 0x1A11C4u: goto label_1a11c4;
            case 0x1A11C8u: goto label_1a11c8;
            case 0x1A1240u: goto label_1a1240;
            case 0x1A1248u: goto label_1a1248;
            case 0x1A124Cu: goto label_1a124c;
            case 0x1A1254u: goto label_1a1254;
            case 0x1A1258u: goto label_1a1258;
            case 0x1A12A0u: goto label_1a12a0;
            case 0x1A12B4u: goto label_1a12b4;
            case 0x1A12D4u: goto label_1a12d4;
            case 0x1A12E8u: goto label_1a12e8;
            case 0x1A1308u: goto label_1a1308;
            case 0x1A1314u: goto label_1a1314;
            case 0x1A134Cu: goto label_1a134c;
            case 0x1A1354u: goto label_1a1354;
            case 0x1A1364u: goto label_1a1364;
            case 0x1A1394u: goto label_1a1394;
            case 0x1A13B4u: goto label_1a13b4;
            case 0x1A13DCu: goto label_1a13dc;
            case 0x1A13E0u: goto label_1a13e0;
            case 0x1A13E4u: goto label_1a13e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A0F68u;
    // 0x1a0f68: 0x0  nop
    ctx->pc = 0x1a0f68u;
    // NOP
    // 0x1a0f6c: 0x0  nop
    ctx->pc = 0x1a0f6cu;
    // NOP
    // 0x1a0f70: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1a0f70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1a0f74: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1a0f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1a0f78: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a0f78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a0f7c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a0f7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a0f80: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1a0f80u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0f84: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a0f84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a0f88: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1a0f88u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0f8c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a0f8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a0f90: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x1a0f90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1a0f94: 0xa31021  addu        $v0, $a1, $v1
    ctx->pc = 0x1a0f94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1a0f98: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1a0f98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a0f9c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1a0f9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1a0fa0: 0x601827  not         $v1, $v1
    ctx->pc = 0x1a0fa0u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1a0fa4: 0xc068580  jal         func_1A1600
    ctx->pc = 0x1A0FA4u;
    SET_GPR_U32(ctx, 31, 0x1A0FACu);
    ctx->pc = 0x1A0FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FA4u;
            // 0x1a0fa8: 0x628024  and         $s0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1600u;
    if (runtime->hasFunction(0x1A1600u)) {
        auto targetFn = runtime->lookupFunction(0x1A1600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0FACu; }
        if (ctx->pc != 0x1A0FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1600_0x1a1600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0FACu; }
        if (ctx->pc != 0x1A0FACu) { return; }
    }
    ctx->pc = 0x1A0FACu;
label_1a0fac:
    // 0x1a0fac: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1a0facu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0fb0: 0x3407ffff  ori         $a3, $zero, 0xFFFF
    ctx->pc = 0x1a0fb0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1a0fb4: 0x16270003  bne         $s1, $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A0FB4u;
    {
        const bool branch_taken_0x1a0fb4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 7));
        if (branch_taken_0x1a0fb4) {
            ctx->pc = 0x1A0FC4u;
            goto label_1a0fc4;
        }
    }
    ctx->pc = 0x1A0FBCu;
    // 0x1a0fbc: 0x100000a5  b           . + 4 + (0xA5 << 2)
    ctx->pc = 0x1A0FBCu;
    {
        const bool branch_taken_0x1a0fbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0FC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FBCu;
            // 0x1a0fc0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0fbc) {
            ctx->pc = 0x1A1254u;
            goto label_1a1254;
        }
    }
    ctx->pc = 0x1A0FC4u;
label_1a0fc4:
    // 0x1a0fc4: 0x8e620024  lw          $v0, 0x24($s3)
    ctx->pc = 0x1a0fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 36)));
    // 0x1a0fc8: 0x14470006  bne         $v0, $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A0FC8u;
    {
        const bool branch_taken_0x1a0fc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 7));
        ctx->pc = 0x1A0FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FC8u;
            // 0x1a0fcc: 0x21900  sll         $v1, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0fc8) {
            ctx->pc = 0x1A0FE4u;
            goto label_1a0fe4;
        }
    }
    ctx->pc = 0x1A0FD0u;
    // 0x1a0fd0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a0fd0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0fd4: 0xc068384  jal         func_1A0E10
    ctx->pc = 0x1A0FD4u;
    SET_GPR_U32(ctx, 31, 0x1A0FDCu);
    ctx->pc = 0x1A0FD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FD4u;
            // 0x1a0fd8: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0E10u;
    goto label_1a0e10;
    ctx->pc = 0x1A0FDCu;
label_1a0fdc:
    // 0x1a0fdc: 0x1000009e  b           . + 4 + (0x9E << 2)
    ctx->pc = 0x1A0FDCu;
    {
        const bool branch_taken_0x1a0fdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FDCu;
            // 0x1a0fe0: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0fdc) {
            ctx->pc = 0x1A1258u;
            goto label_1a1258;
        }
    }
    ctx->pc = 0x1A0FE4u;
label_1a0fe4:
    // 0x1a0fe4: 0x8e64000c  lw          $a0, 0xC($s3)
    ctx->pc = 0x1a0fe4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x1a0fe8: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a0fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a0fec: 0x10800076  beqz        $a0, . + 4 + (0x76 << 2)
    ctx->pc = 0x1A0FECu;
    {
        const bool branch_taken_0x1a0fec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FECu;
            // 0x1a0ff0: 0x431821  addu        $v1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0fec) {
            ctx->pc = 0x1A11C8u;
            goto label_1a11c8;
        }
    }
    ctx->pc = 0x1A0FF4u;
    // 0x1a0ff4: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1A0FF4u;
    {
        const bool branch_taken_0x1a0ff4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FF4u;
            // 0x1a0ff8: 0x9464000e  lhu         $a0, 0xE($v1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0ff4) {
            ctx->pc = 0x1A1098u;
            goto label_1a1098;
        }
    }
    ctx->pc = 0x1A0FFCu;
label_1a0ffc:
    // 0x1a0ffc: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x1a0ffcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a1000: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x1a1000u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1a1004: 0x8c650004  lw          $a1, 0x4($v1)
    ctx->pc = 0x1a1004u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1a1008: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x1a1008u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1a100c: 0x444821  addu        $t1, $v0, $a0
    ctx->pc = 0x1a100cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1a1010: 0x8e680018  lw          $t0, 0x18($s3)
    ctx->pc = 0x1a1010u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1014: 0x8d230000  lw          $v1, 0x0($t1)
    ctx->pc = 0x1a1014u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1a1018: 0xc52821  addu        $a1, $a2, $a1
    ctx->pc = 0x1a1018u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1a101c: 0x2504ffff  addiu       $a0, $t0, -0x1
    ctx->pc = 0x1a101cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x1a1020: 0x1052821  addu        $a1, $t0, $a1
    ctx->pc = 0x1a1020u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x1a1024: 0x802027  not         $a0, $a0
    ctx->pc = 0x1a1024u;
    SET_GPR_U64(ctx, 4, ~(GPR_U64(ctx, 4) | GPR_U64(ctx, 0)));
    // 0x1a1028: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1a1028u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a102c: 0x854024  and         $t0, $a0, $a1
    ctx->pc = 0x1a102cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x1a1030: 0x681823  subu        $v1, $v1, $t0
    ctx->pc = 0x1a1030u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x1a1034: 0x70082b  sltu        $at, $v1, $s0
    ctx->pc = 0x1a1034u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a1038: 0x14200015  bnez        $at, . + 4 + (0x15 << 2)
    ctx->pc = 0x1A1038u;
    {
        const bool branch_taken_0x1a1038 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A103Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1038u;
            // 0x1a103c: 0x113100  sll         $a2, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1038) {
            ctx->pc = 0x1A1090u;
            goto label_1a1090;
        }
    }
    ctx->pc = 0x1A1040u;
    // 0x1a1040: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a1040u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1044: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1a1044u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1a1048: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1a1048u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a104c: 0xa440000a  sh          $zero, 0xA($v0)
    ctx->pc = 0x1a104cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a1050: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a1050u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1054: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1a1054u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1a1058: 0xac520004  sw          $s2, 0x4($v0)
    ctx->pc = 0x1a1058u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 18));
    // 0x1a105c: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a105cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1060: 0x8e630018  lw          $v1, 0x18($s3)
    ctx->pc = 0x1a1060u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1064: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1a1064u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1a1068: 0xa4430008  sh          $v1, 0x8($v0)
    ctx->pc = 0x1a1068u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 8), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a106c: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a106cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1070: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x1a1070u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1a1074: 0xac480000  sw          $t0, 0x0($v0)
    ctx->pc = 0x1a1074u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 8));
    // 0x1a1078: 0x8e62001c  lw          $v0, 0x1C($s3)
    ctx->pc = 0x1a1078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1a107c: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1a107cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1a1080: 0xc06859c  jal         func_1A1670
    ctx->pc = 0x1A1080u;
    SET_GPR_U32(ctx, 31, 0x1A1088u);
    ctx->pc = 0x1A1084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1080u;
            // 0x1a1084: 0xae62001c  sw          $v0, 0x1C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1670u;
    if (runtime->hasFunction(0x1A1670u)) {
        auto targetFn = runtime->lookupFunction(0x1A1670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1088u; }
        if (ctx->pc != 0x1A1088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1670_0x1a1670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1088u; }
        if (ctx->pc != 0x1A1088u) { return; }
    }
    ctx->pc = 0x1A1088u;
label_1a1088:
    // 0x1a1088: 0x10000072  b           . + 4 + (0x72 << 2)
    ctx->pc = 0x1A1088u;
    {
        const bool branch_taken_0x1a1088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A108Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1088u;
            // 0x1a108c: 0x26220001  addiu       $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1088) {
            ctx->pc = 0x1A1254u;
            goto label_1a1254;
        }
    }
    ctx->pc = 0x1A1090u;
label_1a1090:
    // 0x1a1090: 0x120182d  daddu       $v1, $t1, $zero
    ctx->pc = 0x1a1090u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1094: 0x9464000e  lhu         $a0, 0xE($v1)
    ctx->pc = 0x1a1094u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 14)));
label_1a1098:
    // 0x1a1098: 0x1487ffd8  bne         $a0, $a3, . + 4 + (-0x28 << 2)
    ctx->pc = 0x1A1098u;
    {
        const bool branch_taken_0x1a1098 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 7));
        if (branch_taken_0x1a1098) {
            ctx->pc = 0x1A0FFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a0ffc;
        }
    }
    ctx->pc = 0x1A10A0u;
    // 0x1a10a0: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x1a10a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a10a4: 0x8c650004  lw          $a1, 0x4($v1)
    ctx->pc = 0x1a10a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1a10a8: 0x8e670018  lw          $a3, 0x18($s3)
    ctx->pc = 0x1a10a8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a10ac: 0x8e630010  lw          $v1, 0x10($s3)
    ctx->pc = 0x1a10acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1a10b0: 0xc52821  addu        $a1, $a2, $a1
    ctx->pc = 0x1a10b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1a10b4: 0x24e4ffff  addiu       $a0, $a3, -0x1
    ctx->pc = 0x1a10b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1a10b8: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x1a10b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x1a10bc: 0x802027  not         $a0, $a0
    ctx->pc = 0x1a10bcu;
    SET_GPR_U64(ctx, 4, ~(GPR_U64(ctx, 4) | GPR_U64(ctx, 0)));
    // 0x1a10c0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1a10c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a10c4: 0x853024  and         $a2, $a0, $a1
    ctx->pc = 0x1a10c4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x1a10c8: 0x661823  subu        $v1, $v1, $a2
    ctx->pc = 0x1a10c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1a10cc: 0x70082b  sltu        $at, $v1, $s0
    ctx->pc = 0x1a10ccu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a10d0: 0x1420005e  bnez        $at, . + 4 + (0x5E << 2)
    ctx->pc = 0x1A10D0u;
    {
        const bool branch_taken_0x1a10d0 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A10D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A10D0u;
            // 0x1a10d4: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a10d0) {
            ctx->pc = 0x1A124Cu;
            goto label_1a124c;
        }
    }
    ctx->pc = 0x1A10D8u;
    // 0x1a10d8: 0x113900  sll         $a3, $s1, 4
    ctx->pc = 0x1a10d8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
    // 0x1a10dc: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a10dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a10e0: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a10e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a10e4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1a10e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a10e8: 0xa440000a  sh          $zero, 0xA($v0)
    ctx->pc = 0x1a10e8u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a10ec: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a10ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a10f0: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a10f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a10f4: 0xac520004  sw          $s2, 0x4($v0)
    ctx->pc = 0x1a10f4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 18));
    // 0x1a10f8: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a10f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a10fc: 0x8e630018  lw          $v1, 0x18($s3)
    ctx->pc = 0x1a10fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1100: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1100u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1104: 0xa4430008  sh          $v1, 0x8($v0)
    ctx->pc = 0x1a1104u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 8), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a1108: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a1108u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a110c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x1a110cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1a1110: 0xac460000  sw          $a2, 0x0($v0)
    ctx->pc = 0x1a1110u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 6));
    // 0x1a1114: 0x8e62001c  lw          $v0, 0x1C($s3)
    ctx->pc = 0x1a1114u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1a1118: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1a1118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1a111c: 0xc06859c  jal         func_1A1670
    ctx->pc = 0x1A111Cu;
    SET_GPR_U32(ctx, 31, 0x1A1124u);
    ctx->pc = 0x1A1120u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A111Cu;
            // 0x1a1120: 0xae62001c  sw          $v0, 0x1C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1670u;
    if (runtime->hasFunction(0x1A1670u)) {
        auto targetFn = runtime->lookupFunction(0x1A1670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1124u; }
        if (ctx->pc != 0x1A1124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1670_0x1a1670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1124u; }
        if (ctx->pc != 0x1A1124u) { return; }
    }
    ctx->pc = 0x1A1124u;
label_1a1124:
    // 0x1a1124: 0x1000004b  b           . + 4 + (0x4B << 2)
    ctx->pc = 0x1A1124u;
    {
        const bool branch_taken_0x1a1124 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1124u;
            // 0x1a1128: 0x26220001  addiu       $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1124) {
            ctx->pc = 0x1A1254u;
            goto label_1a1254;
        }
    }
    ctx->pc = 0x1A112Cu;
label_1a112c:
    // 0x1a112c: 0x8e690018  lw          $t1, 0x18($s3)
    ctx->pc = 0x1a112cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1130: 0x42900  sll         $a1, $a0, 4
    ctx->pc = 0x1a1130u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1a1134: 0x454021  addu        $t0, $v0, $a1
    ctx->pc = 0x1a1134u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1a1138: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1a1138u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a113c: 0x8d070000  lw          $a3, 0x0($t0)
    ctx->pc = 0x1a113cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1a1140: 0x8d060004  lw          $a2, 0x4($t0)
    ctx->pc = 0x1a1140u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x1a1144: 0x2525ffff  addiu       $a1, $t1, -0x1
    ctx->pc = 0x1a1144u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967295));
    // 0x1a1148: 0xa02827  not         $a1, $a1
    ctx->pc = 0x1a1148u;
    SET_GPR_U64(ctx, 5, ~(GPR_U64(ctx, 5) | GPR_U64(ctx, 0)));
    // 0x1a114c: 0xe63021  addu        $a2, $a3, $a2
    ctx->pc = 0x1a114cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x1a1150: 0x1263021  addu        $a2, $t1, $a2
    ctx->pc = 0x1a1150u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
    // 0x1a1154: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1a1154u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1a1158: 0xa62824  and         $a1, $a1, $a2
    ctx->pc = 0x1a1158u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 6));
    // 0x1a115c: 0x852023  subu        $a0, $a0, $a1
    ctx->pc = 0x1a115cu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1a1160: 0x90082b  sltu        $at, $a0, $s0
    ctx->pc = 0x1a1160u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a1164: 0x14200017  bnez        $at, . + 4 + (0x17 << 2)
    ctx->pc = 0x1A1164u;
    {
        const bool branch_taken_0x1a1164 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A1168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1164u;
            // 0x1a1168: 0x113900  sll         $a3, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1164) {
            ctx->pc = 0x1A11C4u;
            goto label_1a11c4;
        }
    }
    ctx->pc = 0x1A116Cu;
    // 0x1a116c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a116cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1170: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1170u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1174: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1a1174u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1178: 0xa440000a  sh          $zero, 0xA($v0)
    ctx->pc = 0x1a1178u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a117c: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a117cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1180: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1180u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1184: 0xac520004  sw          $s2, 0x4($v0)
    ctx->pc = 0x1a1184u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 18));
    // 0x1a1188: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a1188u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a118c: 0x8e660018  lw          $a2, 0x18($s3)
    ctx->pc = 0x1a118cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1190: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1190u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1194: 0xa4460008  sh          $a2, 0x8($v0)
    ctx->pc = 0x1a1194u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 8), (uint16_t)GPR_U32(ctx, 6));
    // 0x1a1198: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1a1198u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a119c: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a119cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a11a0: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1a11a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a11a4: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x1a11a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1a11a8: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1a11a8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1a11ac: 0x8e62001c  lw          $v0, 0x1C($s3)
    ctx->pc = 0x1a11acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1a11b0: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1a11b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1a11b4: 0xc06859c  jal         func_1A1670
    ctx->pc = 0x1A11B4u;
    SET_GPR_U32(ctx, 31, 0x1A11BCu);
    ctx->pc = 0x1A11B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A11B4u;
            // 0x1a11b8: 0xae62001c  sw          $v0, 0x1C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1670u;
    if (runtime->hasFunction(0x1A1670u)) {
        auto targetFn = runtime->lookupFunction(0x1A1670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A11BCu; }
        if (ctx->pc != 0x1A11BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1670_0x1a1670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A11BCu; }
        if (ctx->pc != 0x1A11BCu) { return; }
    }
    ctx->pc = 0x1A11BCu;
label_1a11bc:
    // 0x1a11bc: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1A11BCu;
    {
        const bool branch_taken_0x1a11bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A11C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A11BCu;
            // 0x1a11c0: 0x26220001  addiu       $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a11bc) {
            ctx->pc = 0x1A1254u;
            goto label_1a1254;
        }
    }
    ctx->pc = 0x1A11C4u;
label_1a11c4:
    // 0x1a11c4: 0x100182d  daddu       $v1, $t0, $zero
    ctx->pc = 0x1a11c4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_1a11c8:
    // 0x1a11c8: 0x9465000e  lhu         $a1, 0xE($v1)
    ctx->pc = 0x1a11c8u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 14)));
    // 0x1a11cc: 0x3404ffff  ori         $a0, $zero, 0xFFFF
    ctx->pc = 0x1a11ccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1a11d0: 0x14a4ffd6  bne         $a1, $a0, . + 4 + (-0x2A << 2)
    ctx->pc = 0x1A11D0u;
    {
        const bool branch_taken_0x1a11d0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 4));
        ctx->pc = 0x1A11D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A11D0u;
            // 0x1a11d4: 0x30a4ffff  andi        $a0, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a11d0) {
            ctx->pc = 0x1A112Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a112c;
        }
    }
    ctx->pc = 0x1A11D8u;
    // 0x1a11d8: 0x8c650000  lw          $a1, 0x0($v1)
    ctx->pc = 0x1a11d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a11dc: 0x8e640010  lw          $a0, 0x10($s3)
    ctx->pc = 0x1a11dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1a11e0: 0xa42023  subu        $a0, $a1, $a0
    ctx->pc = 0x1a11e0u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1a11e4: 0x90082b  sltu        $at, $a0, $s0
    ctx->pc = 0x1a11e4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a11e8: 0x14200017  bnez        $at, . + 4 + (0x17 << 2)
    ctx->pc = 0x1A11E8u;
    {
        const bool branch_taken_0x1a11e8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A11ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A11E8u;
            // 0x1a11ec: 0x113900  sll         $a3, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a11e8) {
            ctx->pc = 0x1A1248u;
            goto label_1a1248;
        }
    }
    ctx->pc = 0x1A11F0u;
    // 0x1a11f0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a11f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a11f4: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a11f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a11f8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1a11f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a11fc: 0xa440000a  sh          $zero, 0xA($v0)
    ctx->pc = 0x1a11fcu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a1200: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a1200u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1204: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1204u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1208: 0xac520004  sw          $s2, 0x4($v0)
    ctx->pc = 0x1a1208u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 18));
    // 0x1a120c: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a120cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1210: 0x8e660018  lw          $a2, 0x18($s3)
    ctx->pc = 0x1a1210u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1214: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1218: 0xa4460008  sh          $a2, 0x8($v0)
    ctx->pc = 0x1a1218u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 8), (uint16_t)GPR_U32(ctx, 6));
    // 0x1a121c: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1a121cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a1220: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a1220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1224: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1a1224u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a1228: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x1a1228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1a122c: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1a122cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1a1230: 0x8e62001c  lw          $v0, 0x1C($s3)
    ctx->pc = 0x1a1230u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1a1234: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1a1234u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1a1238: 0xc06859c  jal         func_1A1670
    ctx->pc = 0x1A1238u;
    SET_GPR_U32(ctx, 31, 0x1A1240u);
    ctx->pc = 0x1A123Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1238u;
            // 0x1a123c: 0xae62001c  sw          $v0, 0x1C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1670u;
    if (runtime->hasFunction(0x1A1670u)) {
        auto targetFn = runtime->lookupFunction(0x1A1670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1240u; }
        if (ctx->pc != 0x1A1240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1670_0x1a1670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1240u; }
        if (ctx->pc != 0x1A1240u) { return; }
    }
    ctx->pc = 0x1A1240u;
label_1a1240:
    // 0x1a1240: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A1240u;
    {
        const bool branch_taken_0x1a1240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1240u;
            // 0x1a1244: 0x26220001  addiu       $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1240) {
            ctx->pc = 0x1A1254u;
            goto label_1a1254;
        }
    }
    ctx->pc = 0x1A1248u;
label_1a1248:
    // 0x1a1248: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a1248u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_1a124c:
    // 0x1a124c: 0xc068384  jal         func_1A0E10
    ctx->pc = 0x1A124Cu;
    SET_GPR_U32(ctx, 31, 0x1A1254u);
    ctx->pc = 0x1A1250u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A124Cu;
            // 0x1a1250: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0E10u;
    goto label_1a0e10;
    ctx->pc = 0x1A1254u;
label_1a1254:
    // 0x1a1254: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1a1254u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1a1258:
    // 0x1a1258: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a1258u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a125c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a125cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a1260: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a1260u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a1264: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a1264u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a1268: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1268u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A126Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1268u;
            // 0x1a126c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A0E10u: goto label_1a0e10;
            case 0x1A0E20u: goto label_1a0e20;
            case 0x1A0E48u: goto label_1a0e48;
            case 0x1A0E60u: goto label_1a0e60;
            case 0x1A0E70u: goto label_1a0e70;
            case 0x1A0E78u: goto label_1a0e78;
            case 0x1A0E90u: goto label_1a0e90;
            case 0x1A0F04u: goto label_1a0f04;
            case 0x1A0F30u: goto label_1a0f30;
            case 0x1A0F48u: goto label_1a0f48;
            case 0x1A0F4Cu: goto label_1a0f4c;
            case 0x1A0FACu: goto label_1a0fac;
            case 0x1A0FC4u: goto label_1a0fc4;
            case 0x1A0FDCu: goto label_1a0fdc;
            case 0x1A0FE4u: goto label_1a0fe4;
            case 0x1A0FFCu: goto label_1a0ffc;
            case 0x1A1088u: goto label_1a1088;
            case 0x1A1090u: goto label_1a1090;
            case 0x1A1098u: goto label_1a1098;
            case 0x1A1124u: goto label_1a1124;
            case 0x1A112Cu: goto label_1a112c;
            case 0x1A11BCu: goto label_1a11bc;
            case 0x1A11C4u: goto label_1a11c4;
            case 0x1A11C8u: goto label_1a11c8;
            case 0x1A1240u: goto label_1a1240;
            case 0x1A1248u: goto label_1a1248;
            case 0x1A124Cu: goto label_1a124c;
            case 0x1A1254u: goto label_1a1254;
            case 0x1A1258u: goto label_1a1258;
            case 0x1A12A0u: goto label_1a12a0;
            case 0x1A12B4u: goto label_1a12b4;
            case 0x1A12D4u: goto label_1a12d4;
            case 0x1A12E8u: goto label_1a12e8;
            case 0x1A1308u: goto label_1a1308;
            case 0x1A1314u: goto label_1a1314;
            case 0x1A134Cu: goto label_1a134c;
            case 0x1A1354u: goto label_1a1354;
            case 0x1A1364u: goto label_1a1364;
            case 0x1A1394u: goto label_1a1394;
            case 0x1A13B4u: goto label_1a13b4;
            case 0x1A13DCu: goto label_1a13dc;
            case 0x1A13E0u: goto label_1a13e0;
            case 0x1A13E4u: goto label_1a13e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1270u;
    // 0x1a1270: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a1270u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a1274: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a1274u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a1278: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a1278u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a127c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a127cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a1280: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a1280u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1284: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x1a1284u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1a1288: 0xa31021  addu        $v0, $a1, $v1
    ctx->pc = 0x1a1288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1a128c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1a128cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a1290: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1a1290u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1a1294: 0x601827  not         $v1, $v1
    ctx->pc = 0x1a1294u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1a1298: 0xc06856c  jal         func_1A15B0
    ctx->pc = 0x1A1298u;
    SET_GPR_U32(ctx, 31, 0x1A12A0u);
    ctx->pc = 0x1A129Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1298u;
            // 0x1a129c: 0x628024  and         $s0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A15B0u;
    if (runtime->hasFunction(0x1A15B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A15B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12A0u; }
        if (ctx->pc != 0x1A12A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A15B0_0x1a15b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12A0u; }
        if (ctx->pc != 0x1A12A0u) { return; }
    }
    ctx->pc = 0x1A12A0u;
label_1a12a0:
    // 0x1a12a0: 0x50082b  sltu        $at, $v0, $s0
    ctx->pc = 0x1a12a0u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a12a4: 0x10200010  beqz        $at, . + 4 + (0x10 << 2)
    ctx->pc = 0x1A12A4u;
    {
        const bool branch_taken_0x1a12a4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A12A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A12A4u;
            // 0x1a12a8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a12a4) {
            ctx->pc = 0x1A12E8u;
            goto label_1a12e8;
        }
    }
    ctx->pc = 0x1A12ACu;
    // 0x1a12ac: 0xc0684fc  jal         func_1A13F0
    ctx->pc = 0x1A12ACu;
    SET_GPR_U32(ctx, 31, 0x1A12B4u);
    ctx->pc = 0x1A13F0u;
    if (runtime->hasFunction(0x1A13F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A13F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12B4u; }
        if (ctx->pc != 0x1A12B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A13F0_0x1a13f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12B4u; }
        if (ctx->pc != 0x1A12B4u) { return; }
    }
    ctx->pc = 0x1A12B4u;
label_1a12b4:
    // 0x1a12b4: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x1a12b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1a12b8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1a12b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a12bc: 0x2443ffff  addiu       $v1, $v0, -0x1
    ctx->pc = 0x1a12bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1a12c0: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1a12c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1a12c4: 0x601827  not         $v1, $v1
    ctx->pc = 0x1a12c4u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1a12c8: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1a12c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1a12cc: 0xc06856c  jal         func_1A15B0
    ctx->pc = 0x1A12CCu;
    SET_GPR_U32(ctx, 31, 0x1A12D4u);
    ctx->pc = 0x1A12D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A12CCu;
            // 0x1a12d0: 0x628024  and         $s0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A15B0u;
    if (runtime->hasFunction(0x1A15B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A15B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12D4u; }
        if (ctx->pc != 0x1A12D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A15B0_0x1a15b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12D4u; }
        if (ctx->pc != 0x1A12D4u) { return; }
    }
    ctx->pc = 0x1A12D4u;
label_1a12d4:
    // 0x1a12d4: 0x50082b  sltu        $at, $v0, $s0
    ctx->pc = 0x1a12d4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a12d8: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A12D8u;
    {
        const bool branch_taken_0x1a12d8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a12d8) {
            ctx->pc = 0x1A12E8u;
            goto label_1a12e8;
        }
    }
    ctx->pc = 0x1A12E0u;
    // 0x1a12e0: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A12E0u;
    {
        const bool branch_taken_0x1a12e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A12E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A12E0u;
            // 0x1a12e4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a12e0) {
            ctx->pc = 0x1A1314u;
            goto label_1a1314;
        }
    }
    ctx->pc = 0x1A12E8u;
label_1a12e8:
    // 0x1a12e8: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x1a12e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1a12ec: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A12ECu;
    {
        const bool branch_taken_0x1a12ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a12ec) {
            ctx->pc = 0x1A1308u;
            goto label_1a1308;
        }
    }
    ctx->pc = 0x1A12F4u;
    // 0x1a12f4: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1a12f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1a12f8: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1a12f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1a12fc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a12fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a1300: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A1300u;
    {
        const bool branch_taken_0x1a1300 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1300u;
            // 0x1a1304: 0x501023  subu        $v0, $v0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1300) {
            ctx->pc = 0x1A1314u;
            goto label_1a1314;
        }
    }
    ctx->pc = 0x1A1308u;
label_1a1308:
    // 0x1a1308: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1a1308u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1a130c: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1a130cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1a1310: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1a1310u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1a1314:
    // 0x1a1314: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a1314u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a1318: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a1318u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a131c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a131cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a1320: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1320u;
            // 0x1a1324: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A0E10u: goto label_1a0e10;
            case 0x1A0E20u: goto label_1a0e20;
            case 0x1A0E48u: goto label_1a0e48;
            case 0x1A0E60u: goto label_1a0e60;
            case 0x1A0E70u: goto label_1a0e70;
            case 0x1A0E78u: goto label_1a0e78;
            case 0x1A0E90u: goto label_1a0e90;
            case 0x1A0F04u: goto label_1a0f04;
            case 0x1A0F30u: goto label_1a0f30;
            case 0x1A0F48u: goto label_1a0f48;
            case 0x1A0F4Cu: goto label_1a0f4c;
            case 0x1A0FACu: goto label_1a0fac;
            case 0x1A0FC4u: goto label_1a0fc4;
            case 0x1A0FDCu: goto label_1a0fdc;
            case 0x1A0FE4u: goto label_1a0fe4;
            case 0x1A0FFCu: goto label_1a0ffc;
            case 0x1A1088u: goto label_1a1088;
            case 0x1A1090u: goto label_1a1090;
            case 0x1A1098u: goto label_1a1098;
            case 0x1A1124u: goto label_1a1124;
            case 0x1A112Cu: goto label_1a112c;
            case 0x1A11BCu: goto label_1a11bc;
            case 0x1A11C4u: goto label_1a11c4;
            case 0x1A11C8u: goto label_1a11c8;
            case 0x1A1240u: goto label_1a1240;
            case 0x1A1248u: goto label_1a1248;
            case 0x1A124Cu: goto label_1a124c;
            case 0x1A1254u: goto label_1a1254;
            case 0x1A1258u: goto label_1a1258;
            case 0x1A12A0u: goto label_1a12a0;
            case 0x1A12B4u: goto label_1a12b4;
            case 0x1A12D4u: goto label_1a12d4;
            case 0x1A12E8u: goto label_1a12e8;
            case 0x1A1308u: goto label_1a1308;
            case 0x1A1314u: goto label_1a1314;
            case 0x1A134Cu: goto label_1a134c;
            case 0x1A1354u: goto label_1a1354;
            case 0x1A1364u: goto label_1a1364;
            case 0x1A1394u: goto label_1a1394;
            case 0x1A13B4u: goto label_1a13b4;
            case 0x1A13DCu: goto label_1a13dc;
            case 0x1A13E0u: goto label_1a13e0;
            case 0x1A13E4u: goto label_1a13e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1328u;
    // 0x1a1328: 0x0  nop
    ctx->pc = 0x1a1328u;
    // NOP
    // 0x1a132c: 0x0  nop
    ctx->pc = 0x1a132cu;
    // NOP
    // 0x1a1330: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a1330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a1334: 0x24a3ffff  addiu       $v1, $a1, -0x1
    ctx->pc = 0x1a1334u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a1338: 0x62082a  slt         $at, $v1, $v0
    ctx->pc = 0x1a1338u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a133c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A133Cu;
    {
        const bool branch_taken_0x1a133c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A133Cu;
            // 0x1a1340: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a133c) {
            ctx->pc = 0x1A134Cu;
            goto label_1a134c;
        }
    }
    ctx->pc = 0x1A1344u;
    // 0x1a1344: 0x14a00003  bnez        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A1344u;
    {
        const bool branch_taken_0x1a1344 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a1344) {
            ctx->pc = 0x1A1354u;
            goto label_1a1354;
        }
    }
    ctx->pc = 0x1A134Cu;
label_1a134c:
    // 0x1a134c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A134Cu;
    {
        const bool branch_taken_0x1a134c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a134c) {
            ctx->pc = 0x1A1364u;
            goto label_1a1364;
        }
    }
    ctx->pc = 0x1A1354u;
label_1a1354:
    // 0x1a1354: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a1354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a1358: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1a1358u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1a135c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a135cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a1360: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1a1360u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1a1364:
    // 0x1a1364: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1364u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A0E10u: goto label_1a0e10;
            case 0x1A0E20u: goto label_1a0e20;
            case 0x1A0E48u: goto label_1a0e48;
            case 0x1A0E60u: goto label_1a0e60;
            case 0x1A0E70u: goto label_1a0e70;
            case 0x1A0E78u: goto label_1a0e78;
            case 0x1A0E90u: goto label_1a0e90;
            case 0x1A0F04u: goto label_1a0f04;
            case 0x1A0F30u: goto label_1a0f30;
            case 0x1A0F48u: goto label_1a0f48;
            case 0x1A0F4Cu: goto label_1a0f4c;
            case 0x1A0FACu: goto label_1a0fac;
            case 0x1A0FC4u: goto label_1a0fc4;
            case 0x1A0FDCu: goto label_1a0fdc;
            case 0x1A0FE4u: goto label_1a0fe4;
            case 0x1A0FFCu: goto label_1a0ffc;
            case 0x1A1088u: goto label_1a1088;
            case 0x1A1090u: goto label_1a1090;
            case 0x1A1098u: goto label_1a1098;
            case 0x1A1124u: goto label_1a1124;
            case 0x1A112Cu: goto label_1a112c;
            case 0x1A11BCu: goto label_1a11bc;
            case 0x1A11C4u: goto label_1a11c4;
            case 0x1A11C8u: goto label_1a11c8;
            case 0x1A1240u: goto label_1a1240;
            case 0x1A1248u: goto label_1a1248;
            case 0x1A124Cu: goto label_1a124c;
            case 0x1A1254u: goto label_1a1254;
            case 0x1A1258u: goto label_1a1258;
            case 0x1A12A0u: goto label_1a12a0;
            case 0x1A12B4u: goto label_1a12b4;
            case 0x1A12D4u: goto label_1a12d4;
            case 0x1A12E8u: goto label_1a12e8;
            case 0x1A1308u: goto label_1a1308;
            case 0x1A1314u: goto label_1a1314;
            case 0x1A134Cu: goto label_1a134c;
            case 0x1A1354u: goto label_1a1354;
            case 0x1A1364u: goto label_1a1364;
            case 0x1A1394u: goto label_1a1394;
            case 0x1A13B4u: goto label_1a13b4;
            case 0x1A13DCu: goto label_1a13dc;
            case 0x1A13E0u: goto label_1a13e0;
            case 0x1A13E4u: goto label_1a13e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A136Cu;
    // 0x1a136c: 0x0  nop
    ctx->pc = 0x1a136cu;
    // NOP
    // 0x1a1370: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a1370u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a1374: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1a1374u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a1378: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a1378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a137c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a137cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a1380: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x1a1380u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a1384: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A1384u;
    {
        const bool branch_taken_0x1a1384 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A1388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1384u;
            // 0x1a1388: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1384) {
            ctx->pc = 0x1A1394u;
            goto label_1a1394;
        }
    }
    ctx->pc = 0x1A138Cu;
    // 0x1a138c: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1A138Cu;
    {
        const bool branch_taken_0x1a138c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A138Cu;
            // 0x1a1390: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a138c) {
            ctx->pc = 0x1A13E4u;
            goto label_1a13e4;
        }
    }
    ctx->pc = 0x1A1394u;
label_1a1394:
    // 0x1a1394: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a1394u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a1398: 0x51900  sll         $v1, $a1, 4
    ctx->pc = 0x1a1398u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1a139c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a139cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a13a0: 0x8c460004  lw          $a2, 0x4($v0)
    ctx->pc = 0x1a13a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a13a4: 0x14c00003  bnez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A13A4u;
    {
        const bool branch_taken_0x1a13a4 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A13A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A13A4u;
            // 0x1a13a8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a13a4) {
            ctx->pc = 0x1A13B4u;
            goto label_1a13b4;
        }
    }
    ctx->pc = 0x1A13ACu;
    // 0x1a13ac: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A13ACu;
    {
        const bool branch_taken_0x1a13ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a13ac) {
            ctx->pc = 0x1A13E0u;
            goto label_1a13e0;
        }
    }
    ctx->pc = 0x1A13B4u;
label_1a13b4:
    // 0x1a13b4: 0x8c82001c  lw          $v0, 0x1C($a0)
    ctx->pc = 0x1a13b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x1a13b8: 0x461023  subu        $v0, $v0, $a2
    ctx->pc = 0x1a13b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1a13bc: 0xac82001c  sw          $v0, 0x1C($a0)
    ctx->pc = 0x1a13bcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 2));
    // 0x1a13c0: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a13c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a13c4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a13c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a13c8: 0xac400004  sw          $zero, 0x4($v0)
    ctx->pc = 0x1a13c8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x1a13cc: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a13ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a13d0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a13d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a13d4: 0xc0685e8  jal         func_1A17A0
    ctx->pc = 0x1A13D4u;
    SET_GPR_U32(ctx, 31, 0x1A13DCu);
    ctx->pc = 0x1A13D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A13D4u;
            // 0x1a13d8: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A17A0u;
    if (runtime->hasFunction(0x1A17A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A17A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A13DCu; }
        if (ctx->pc != 0x1A13DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A17A0_0x1a17a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A13DCu; }
        if (ctx->pc != 0x1A13DCu) { return; }
    }
    ctx->pc = 0x1A13DCu;
label_1a13dc:
    // 0x1a13dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a13dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1a13e0:
    // 0x1a13e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a13e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a13e4:
    // 0x1a13e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A13E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A13E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A13E4u;
            // 0x1a13e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A0E10u: goto label_1a0e10;
            case 0x1A0E20u: goto label_1a0e20;
            case 0x1A0E48u: goto label_1a0e48;
            case 0x1A0E60u: goto label_1a0e60;
            case 0x1A0E70u: goto label_1a0e70;
            case 0x1A0E78u: goto label_1a0e78;
            case 0x1A0E90u: goto label_1a0e90;
            case 0x1A0F04u: goto label_1a0f04;
            case 0x1A0F30u: goto label_1a0f30;
            case 0x1A0F48u: goto label_1a0f48;
            case 0x1A0F4Cu: goto label_1a0f4c;
            case 0x1A0FACu: goto label_1a0fac;
            case 0x1A0FC4u: goto label_1a0fc4;
            case 0x1A0FDCu: goto label_1a0fdc;
            case 0x1A0FE4u: goto label_1a0fe4;
            case 0x1A0FFCu: goto label_1a0ffc;
            case 0x1A1088u: goto label_1a1088;
            case 0x1A1090u: goto label_1a1090;
            case 0x1A1098u: goto label_1a1098;
            case 0x1A1124u: goto label_1a1124;
            case 0x1A112Cu: goto label_1a112c;
            case 0x1A11BCu: goto label_1a11bc;
            case 0x1A11C4u: goto label_1a11c4;
            case 0x1A11C8u: goto label_1a11c8;
            case 0x1A1240u: goto label_1a1240;
            case 0x1A1248u: goto label_1a1248;
            case 0x1A124Cu: goto label_1a124c;
            case 0x1A1254u: goto label_1a1254;
            case 0x1A1258u: goto label_1a1258;
            case 0x1A12A0u: goto label_1a12a0;
            case 0x1A12B4u: goto label_1a12b4;
            case 0x1A12D4u: goto label_1a12d4;
            case 0x1A12E8u: goto label_1a12e8;
            case 0x1A1308u: goto label_1a1308;
            case 0x1A1314u: goto label_1a1314;
            case 0x1A134Cu: goto label_1a134c;
            case 0x1A1354u: goto label_1a1354;
            case 0x1A1364u: goto label_1a1364;
            case 0x1A1394u: goto label_1a1394;
            case 0x1A13B4u: goto label_1a13b4;
            case 0x1A13DCu: goto label_1a13dc;
            case 0x1A13E0u: goto label_1a13e0;
            case 0x1A13E4u: goto label_1a13e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A13ECu;
    // 0x1a13ec: 0x0  nop
    ctx->pc = 0x1a13ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
