#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BCD30
// Address: 0x1bcd30 - 0x1bcf60
void sub_001BCD30_0x1bcd30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BCD30_0x1bcd30");
#endif

    switch (ctx->pc) {
        case 0x1bcd54u: goto label_1bcd54;
        case 0x1bcd5cu: goto label_1bcd5c;
        case 0x1bcd64u: goto label_1bcd64;
        case 0x1bcd9cu: goto label_1bcd9c;
        case 0x1bce48u: goto label_1bce48;
        case 0x1bce90u: goto label_1bce90;
        case 0x1bcea0u: goto label_1bcea0;
        case 0x1bceb0u: goto label_1bceb0;
        case 0x1bceb8u: goto label_1bceb8;
        case 0x1bcec8u: goto label_1bcec8;
        case 0x1bcf04u: goto label_1bcf04;
        case 0x1bcf14u: goto label_1bcf14;
        case 0x1bcf24u: goto label_1bcf24;
        case 0x1bcf2cu: goto label_1bcf2c;
        case 0x1bcf3cu: goto label_1bcf3c;
        default: break;
    }

    ctx->pc = 0x1bcd30u;

    // 0x1bcd30: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1bcd30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1bcd34: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bcd34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bcd38: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1bcd38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1bcd3c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bcd3cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bcd40: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bcd40u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bcd44: 0x94314300  lhu         $s1, 0x4300($at)
    ctx->pc = 0x1bcd44u;
    SET_GPR_U32(ctx, 17, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17152)));
    // 0x1bcd48: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1bcd48u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bcd4c: 0xc06d584  jal         func_1B5610
    ctx->pc = 0x1BCD4Cu;
    SET_GPR_U32(ctx, 31, 0x1BCD54u);
    ctx->pc = 0x1BCD50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCD4Cu;
            // 0x1bcd50: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5610u;
    if (runtime->hasFunction(0x1B5610u)) {
        auto targetFn = runtime->lookupFunction(0x1B5610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD54u; }
        if (ctx->pc != 0x1BCD54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5610_0x1b5610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD54u; }
        if (ctx->pc != 0x1BCD54u) { return; }
    }
    ctx->pc = 0x1BCD54u;
label_1bcd54:
    // 0x1bcd54: 0xc06d574  jal         func_1B55D0
    ctx->pc = 0x1BCD54u;
    SET_GPR_U32(ctx, 31, 0x1BCD5Cu);
    ctx->pc = 0x1BCD58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCD54u;
            // 0x1bcd58: 0x24040014  addiu       $a0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B55D0u;
    if (runtime->hasFunction(0x1B55D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD5Cu; }
        if (ctx->pc != 0x1BCD5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55D0_0x1b55d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD5Cu; }
        if (ctx->pc != 0x1BCD5Cu) { return; }
    }
    ctx->pc = 0x1BCD5Cu;
label_1bcd5c:
    // 0x1bcd5c: 0xc06d590  jal         func_1B5640
    ctx->pc = 0x1BCD5Cu;
    SET_GPR_U32(ctx, 31, 0x1BCD64u);
    ctx->pc = 0x1BCD60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCD5Cu;
            // 0x1bcd60: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5640u;
    if (runtime->hasFunction(0x1B5640u)) {
        auto targetFn = runtime->lookupFunction(0x1B5640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD64u; }
        if (ctx->pc != 0x1BCD64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5640_0x1b5640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD64u; }
        if (ctx->pc != 0x1BCD64u) { return; }
    }
    ctx->pc = 0x1BCD64u;
label_1bcd64:
    // 0x1bcd64: 0x9203000a  lbu         $v1, 0xA($s0)
    ctx->pc = 0x1bcd64u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bcd68: 0x2402005b  addiu       $v0, $zero, 0x5B
    ctx->pc = 0x1bcd68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 91));
    // 0x1bcd6c: 0x10620058  beq         $v1, $v0, . + 4 + (0x58 << 2)
    ctx->pc = 0x1BCD6Cu;
    {
        const bool branch_taken_0x1bcd6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BCD70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCD6Cu;
            // 0x1bcd70: 0x2402005a  addiu       $v0, $zero, 0x5A (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcd6c) {
            ctx->pc = 0x1BCED0u;
            goto label_1bced0;
        }
    }
    ctx->pc = 0x1BCD74u;
    // 0x1bcd74: 0x10620039  beq         $v1, $v0, . + 4 + (0x39 << 2)
    ctx->pc = 0x1BCD74u;
    {
        const bool branch_taken_0x1bcd74 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BCD78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCD74u;
            // 0x1bcd78: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcd74) {
            ctx->pc = 0x1BCE5Cu;
            goto label_1bce5c;
        }
    }
    ctx->pc = 0x1BCD7Cu;
    // 0x1bcd7c: 0x10640030  beq         $v1, $a0, . + 4 + (0x30 << 2)
    ctx->pc = 0x1BCD7Cu;
    {
        const bool branch_taken_0x1bcd7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1bcd7c) {
            ctx->pc = 0x1BCE40u;
            goto label_1bce40;
        }
    }
    ctx->pc = 0x1BCD84u;
    // 0x1bcd84: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BCD84u;
    {
        const bool branch_taken_0x1bcd84 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcd84) {
            ctx->pc = 0x1BCD94u;
            goto label_1bcd94;
        }
    }
    ctx->pc = 0x1BCD8Cu;
    // 0x1bcd8c: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x1BCD8Cu;
    {
        const bool branch_taken_0x1bcd8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCD90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCD8Cu;
            // 0x1bcd90: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcd8c) {
            ctx->pc = 0x1BCF40u;
            goto label_1bcf40;
        }
    }
    ctx->pc = 0x1BCD94u;
label_1bcd94:
    // 0x1bcd94: 0xc06f5a4  jal         func_1BD690
    ctx->pc = 0x1BCD94u;
    SET_GPR_U32(ctx, 31, 0x1BCD9Cu);
    ctx->pc = 0x1BD690u;
    if (runtime->hasFunction(0x1BD690u)) {
        auto targetFn = runtime->lookupFunction(0x1BD690u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD9Cu; }
        if (ctx->pc != 0x1BCD9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD690_0x1bd690(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD9Cu; }
        if (ctx->pc != 0x1BCD9Cu) { return; }
    }
    ctx->pc = 0x1BCD9Cu;
label_1bcd9c:
    // 0x1bcd9c: 0x2403fffa  addiu       $v1, $zero, -0x6
    ctx->pc = 0x1bcd9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967290));
    // 0x1bcda0: 0x1043001f  beq         $v0, $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x1BCDA0u;
    {
        const bool branch_taken_0x1bcda0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BCDA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCDA0u;
            // 0x1bcda4: 0x2403fffe  addiu       $v1, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcda0) {
            ctx->pc = 0x1BCE20u;
            goto label_1bce20;
        }
    }
    ctx->pc = 0x1BCDA8u;
    // 0x1bcda8: 0x10430017  beq         $v0, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1BCDA8u;
    {
        const bool branch_taken_0x1bcda8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BCDACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCDA8u;
            // 0x1bcdac: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcda8) {
            ctx->pc = 0x1BCE08u;
            goto label_1bce08;
        }
    }
    ctx->pc = 0x1BCDB0u;
    // 0x1bcdb0: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x1bcdb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1bcdb4: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1BCDB4u;
    {
        const bool branch_taken_0x1bcdb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BCDB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCDB4u;
            // 0x1bcdb8: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcdb4) {
            ctx->pc = 0x1BCDF8u;
            goto label_1bcdf8;
        }
    }
    ctx->pc = 0x1BCDBCu;
    // 0x1bcdbc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1bcdbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1bcdc0: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1BCDC0u;
    {
        const bool branch_taken_0x1bcdc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BCDC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCDC0u;
            // 0x1bcdc4: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcdc0) {
            ctx->pc = 0x1BCDECu;
            goto label_1bcdec;
        }
    }
    ctx->pc = 0x1BCDC8u;
    // 0x1bcdc8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BCDC8u;
    {
        const bool branch_taken_0x1bcdc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcdc8) {
            ctx->pc = 0x1BCDD8u;
            goto label_1bcdd8;
        }
    }
    ctx->pc = 0x1BCDD0u;
    // 0x1bcdd0: 0x1000005a  b           . + 4 + (0x5A << 2)
    ctx->pc = 0x1BCDD0u;
    {
        const bool branch_taken_0x1bcdd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcdd0) {
            ctx->pc = 0x1BCF3Cu;
            goto label_1bcf3c;
        }
    }
    ctx->pc = 0x1BCDD8u;
label_1bcdd8:
    // 0x1bcdd8: 0x9202000a  lbu         $v0, 0xA($s0)
    ctx->pc = 0x1bcdd8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bcddc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bcddcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bcde0: 0xa202000a  sb          $v0, 0xA($s0)
    ctx->pc = 0x1bcde0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bcde4: 0x10000055  b           . + 4 + (0x55 << 2)
    ctx->pc = 0x1BCDE4u;
    {
        const bool branch_taken_0x1bcde4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCDE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCDE4u;
            // 0x1bcde8: 0xa200000b  sb          $zero, 0xB($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcde4) {
            ctx->pc = 0x1BCF3Cu;
            goto label_1bcf3c;
        }
    }
    ctx->pc = 0x1BCDECu;
label_1bcdec:
    // 0x1bcdec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1bcdecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bcdf0: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x1BCDF0u;
    {
        const bool branch_taken_0x1bcdf0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCDF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCDF0u;
            // 0x1bcdf4: 0xa02043d1  sb          $zero, 0x43D1($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17361), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcdf0) {
            ctx->pc = 0x1BCF40u;
            goto label_1bcf40;
        }
    }
    ctx->pc = 0x1BCDF8u;
label_1bcdf8:
    // 0x1bcdf8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bcdf8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bcdfc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1bcdfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bce00: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x1BCE00u;
    {
        const bool branch_taken_0x1bce00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCE04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCE00u;
            // 0x1bce04: 0xa02343d1  sb          $v1, 0x43D1($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17361), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bce00) {
            ctx->pc = 0x1BCF40u;
            goto label_1bcf40;
        }
    }
    ctx->pc = 0x1BCE08u;
label_1bce08:
    // 0x1bce08: 0x2402005a  addiu       $v0, $zero, 0x5A
    ctx->pc = 0x1bce08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x1bce0c: 0xa02043d1  sb          $zero, 0x43D1($at)
    ctx->pc = 0x1bce0cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17361), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bce10: 0xa202000a  sb          $v0, 0xA($s0)
    ctx->pc = 0x1bce10u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bce14: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1bce14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1bce18: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1BCE18u;
    {
        const bool branch_taken_0x1bce18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCE1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCE18u;
            // 0x1bce1c: 0xa202000b  sb          $v0, 0xB($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bce18) {
            ctx->pc = 0x1BCF3Cu;
            goto label_1bcf3c;
        }
    }
    ctx->pc = 0x1BCE20u;
label_1bce20:
    // 0x1bce20: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bce20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bce24: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bce24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bce28: 0xa02243d1  sb          $v0, 0x43D1($at)
    ctx->pc = 0x1bce28u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17361), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bce2c: 0x2403005b  addiu       $v1, $zero, 0x5B
    ctx->pc = 0x1bce2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 91));
    // 0x1bce30: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1bce30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1bce34: 0xa203000a  sb          $v1, 0xA($s0)
    ctx->pc = 0x1bce34u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bce38: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1BCE38u;
    {
        const bool branch_taken_0x1bce38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCE3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCE38u;
            // 0x1bce3c: 0xa202000b  sb          $v0, 0xB($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bce38) {
            ctx->pc = 0x1BCF3Cu;
            goto label_1bcf3c;
        }
    }
    ctx->pc = 0x1BCE40u;
label_1bce40:
    // 0x1bce40: 0xc06f8a0  jal         func_1BE280
    ctx->pc = 0x1BCE40u;
    SET_GPR_U32(ctx, 31, 0x1BCE48u);
    ctx->pc = 0x1BE280u;
    if (runtime->hasFunction(0x1BE280u)) {
        auto targetFn = runtime->lookupFunction(0x1BE280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCE48u; }
        if (ctx->pc != 0x1BCE48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE280_0x1be280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCE48u; }
        if (ctx->pc != 0x1BCE48u) { return; }
    }
    ctx->pc = 0x1BCE48u;
label_1bce48:
    // 0x1bce48: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bce48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bce4c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bce4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bce50: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1bce50u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bce54: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1BCE54u;
    {
        const bool branch_taken_0x1bce54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCE58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCE54u;
            // 0x1bce58: 0xa02343d1  sb          $v1, 0x43D1($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17361), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bce54) {
            ctx->pc = 0x1BCF40u;
            goto label_1bcf40;
        }
    }
    ctx->pc = 0x1BCE5Cu;
label_1bce5c:
    // 0x1bce5c: 0x9202000b  lbu         $v0, 0xB($s0)
    ctx->pc = 0x1bce5cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 11)));
    // 0x1bce60: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BCE60u;
    {
        const bool branch_taken_0x1bce60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bce60) {
            ctx->pc = 0x1BCE74u;
            goto label_1bce74;
        }
    }
    ctx->pc = 0x1BCE68u;
    // 0x1bce68: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1bce68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1bce6c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1BCE6Cu;
    {
        const bool branch_taken_0x1bce6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCE70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCE6Cu;
            // 0x1bce70: 0xa202000b  sb          $v0, 0xB($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bce6c) {
            ctx->pc = 0x1BCEB0u;
            goto label_1bceb0;
        }
    }
    ctx->pc = 0x1BCE74u;
label_1bce74:
    // 0x1bce74: 0x3222ffff  andi        $v0, $s1, 0xFFFF
    ctx->pc = 0x1bce74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
    // 0x1bce78: 0x3042fff0  andi        $v0, $v0, 0xFFF0
    ctx->pc = 0x1bce78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65520);
    // 0x1bce7c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1BCE7Cu;
    {
        const bool branch_taken_0x1bce7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCE80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCE7Cu;
            // 0x1bce80: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bce7c) {
            ctx->pc = 0x1BCE98u;
            goto label_1bce98;
        }
    }
    ctx->pc = 0x1BCE84u;
    // 0x1bce84: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1bce84u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bce88: 0xc06e1f8  jal         func_1B87E0
    ctx->pc = 0x1BCE88u;
    SET_GPR_U32(ctx, 31, 0x1BCE90u);
    ctx->pc = 0x1BCE8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCE88u;
            // 0x1bce8c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B87E0u;
    if (runtime->hasFunction(0x1B87E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B87E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCE90u; }
        if (ctx->pc != 0x1BCE90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B87E0_0x1b87e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCE90u; }
        if (ctx->pc != 0x1BCE90u) { return; }
    }
    ctx->pc = 0x1BCE90u;
label_1bce90:
    // 0x1bce90: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1BCE90u;
    {
        const bool branch_taken_0x1bce90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCE94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCE90u;
            // 0x1bce94: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bce90) {
            ctx->pc = 0x1BCF40u;
            goto label_1bcf40;
        }
    }
    ctx->pc = 0x1BCE98u;
label_1bce98:
    // 0x1bce98: 0xc0707b8  jal         func_1C1EE0
    ctx->pc = 0x1BCE98u;
    SET_GPR_U32(ctx, 31, 0x1BCEA0u);
    ctx->pc = 0x1C1EE0u;
    if (runtime->hasFunction(0x1C1EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1C1EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCEA0u; }
        if (ctx->pc != 0x1BCEA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1EE0_0x1c1ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCEA0u; }
        if (ctx->pc != 0x1BCEA0u) { return; }
    }
    ctx->pc = 0x1BCEA0u;
label_1bcea0:
    // 0x1bcea0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1bcea0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bcea4: 0x24050030  addiu       $a1, $zero, 0x30
    ctx->pc = 0x1bcea4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1bcea8: 0xc070920  jal         func_1C2480
    ctx->pc = 0x1BCEA8u;
    SET_GPR_U32(ctx, 31, 0x1BCEB0u);
    ctx->pc = 0x1BCEACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCEA8u;
            // 0x1bceac: 0x24060188  addiu       $a2, $zero, 0x188 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2480u;
    if (runtime->hasFunction(0x1C2480u)) {
        auto targetFn = runtime->lookupFunction(0x1C2480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCEB0u; }
        if (ctx->pc != 0x1BCEB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2480_0x1c2480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCEB0u; }
        if (ctx->pc != 0x1BCEB0u) { return; }
    }
    ctx->pc = 0x1BCEB0u;
label_1bceb0:
    // 0x1bceb0: 0xc0707b8  jal         func_1C1EE0
    ctx->pc = 0x1BCEB0u;
    SET_GPR_U32(ctx, 31, 0x1BCEB8u);
    ctx->pc = 0x1BCEB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCEB0u;
            // 0x1bceb4: 0x24040007  addiu       $a0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1EE0u;
    if (runtime->hasFunction(0x1C1EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1C1EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCEB8u; }
        if (ctx->pc != 0x1BCEB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1EE0_0x1c1ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCEB8u; }
        if (ctx->pc != 0x1BCEB8u) { return; }
    }
    ctx->pc = 0x1BCEB8u;
label_1bceb8:
    // 0x1bceb8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1bceb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bcebc: 0x24050030  addiu       $a1, $zero, 0x30
    ctx->pc = 0x1bcebcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1bcec0: 0xc070920  jal         func_1C2480
    ctx->pc = 0x1BCEC0u;
    SET_GPR_U32(ctx, 31, 0x1BCEC8u);
    ctx->pc = 0x1BCEC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCEC0u;
            // 0x1bcec4: 0x24060138  addiu       $a2, $zero, 0x138 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 312));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2480u;
    if (runtime->hasFunction(0x1C2480u)) {
        auto targetFn = runtime->lookupFunction(0x1C2480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCEC8u; }
        if (ctx->pc != 0x1BCEC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2480_0x1c2480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCEC8u; }
        if (ctx->pc != 0x1BCEC8u) { return; }
    }
    ctx->pc = 0x1BCEC8u;
label_1bcec8:
    // 0x1bcec8: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1BCEC8u;
    {
        const bool branch_taken_0x1bcec8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcec8) {
            ctx->pc = 0x1BCF3Cu;
            goto label_1bcf3c;
        }
    }
    ctx->pc = 0x1BCED0u;
label_1bced0:
    // 0x1bced0: 0x9202000b  lbu         $v0, 0xB($s0)
    ctx->pc = 0x1bced0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 11)));
    // 0x1bced4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BCED4u;
    {
        const bool branch_taken_0x1bced4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bced4) {
            ctx->pc = 0x1BCEE8u;
            goto label_1bcee8;
        }
    }
    ctx->pc = 0x1BCEDCu;
    // 0x1bcedc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1bcedcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1bcee0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1BCEE0u;
    {
        const bool branch_taken_0x1bcee0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCEE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCEE0u;
            // 0x1bcee4: 0xa202000b  sb          $v0, 0xB($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcee0) {
            ctx->pc = 0x1BCF24u;
            goto label_1bcf24;
        }
    }
    ctx->pc = 0x1BCEE8u;
label_1bcee8:
    // 0x1bcee8: 0x3222ffff  andi        $v0, $s1, 0xFFFF
    ctx->pc = 0x1bcee8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
    // 0x1bceec: 0x3042fff0  andi        $v0, $v0, 0xFFF0
    ctx->pc = 0x1bceecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65520);
    // 0x1bcef0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1BCEF0u;
    {
        const bool branch_taken_0x1bcef0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCEF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCEF0u;
            // 0x1bcef4: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcef0) {
            ctx->pc = 0x1BCF0Cu;
            goto label_1bcf0c;
        }
    }
    ctx->pc = 0x1BCEF8u;
    // 0x1bcef8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1bcef8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bcefc: 0xc06e1f8  jal         func_1B87E0
    ctx->pc = 0x1BCEFCu;
    SET_GPR_U32(ctx, 31, 0x1BCF04u);
    ctx->pc = 0x1BCF00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCEFCu;
            // 0x1bcf00: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B87E0u;
    if (runtime->hasFunction(0x1B87E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B87E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF04u; }
        if (ctx->pc != 0x1BCF04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B87E0_0x1b87e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF04u; }
        if (ctx->pc != 0x1BCF04u) { return; }
    }
    ctx->pc = 0x1BCF04u;
label_1bcf04:
    // 0x1bcf04: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1BCF04u;
    {
        const bool branch_taken_0x1bcf04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCF08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCF04u;
            // 0x1bcf08: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcf04) {
            ctx->pc = 0x1BCF40u;
            goto label_1bcf40;
        }
    }
    ctx->pc = 0x1BCF0Cu;
label_1bcf0c:
    // 0x1bcf0c: 0xc0707b8  jal         func_1C1EE0
    ctx->pc = 0x1BCF0Cu;
    SET_GPR_U32(ctx, 31, 0x1BCF14u);
    ctx->pc = 0x1C1EE0u;
    if (runtime->hasFunction(0x1C1EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1C1EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF14u; }
        if (ctx->pc != 0x1BCF14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1EE0_0x1c1ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF14u; }
        if (ctx->pc != 0x1BCF14u) { return; }
    }
    ctx->pc = 0x1BCF14u;
label_1bcf14:
    // 0x1bcf14: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1bcf14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bcf18: 0x24050030  addiu       $a1, $zero, 0x30
    ctx->pc = 0x1bcf18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1bcf1c: 0xc070920  jal         func_1C2480
    ctx->pc = 0x1BCF1Cu;
    SET_GPR_U32(ctx, 31, 0x1BCF24u);
    ctx->pc = 0x1BCF20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCF1Cu;
            // 0x1bcf20: 0x24060188  addiu       $a2, $zero, 0x188 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2480u;
    if (runtime->hasFunction(0x1C2480u)) {
        auto targetFn = runtime->lookupFunction(0x1C2480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF24u; }
        if (ctx->pc != 0x1BCF24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2480_0x1c2480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF24u; }
        if (ctx->pc != 0x1BCF24u) { return; }
    }
    ctx->pc = 0x1BCF24u;
label_1bcf24:
    // 0x1bcf24: 0xc0707b8  jal         func_1C1EE0
    ctx->pc = 0x1BCF24u;
    SET_GPR_U32(ctx, 31, 0x1BCF2Cu);
    ctx->pc = 0x1BCF28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCF24u;
            // 0x1bcf28: 0x24040006  addiu       $a0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1EE0u;
    if (runtime->hasFunction(0x1C1EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1C1EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF2Cu; }
        if (ctx->pc != 0x1BCF2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1EE0_0x1c1ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF2Cu; }
        if (ctx->pc != 0x1BCF2Cu) { return; }
    }
    ctx->pc = 0x1BCF2Cu;
label_1bcf2c:
    // 0x1bcf2c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1bcf2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bcf30: 0x24050030  addiu       $a1, $zero, 0x30
    ctx->pc = 0x1bcf30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1bcf34: 0xc070920  jal         func_1C2480
    ctx->pc = 0x1BCF34u;
    SET_GPR_U32(ctx, 31, 0x1BCF3Cu);
    ctx->pc = 0x1BCF38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCF34u;
            // 0x1bcf38: 0x24060138  addiu       $a2, $zero, 0x138 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 312));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2480u;
    if (runtime->hasFunction(0x1C2480u)) {
        auto targetFn = runtime->lookupFunction(0x1C2480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF3Cu; }
        if (ctx->pc != 0x1BCF3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2480_0x1c2480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF3Cu; }
        if (ctx->pc != 0x1BCF3Cu) { return; }
    }
    ctx->pc = 0x1BCF3Cu;
label_1bcf3c:
    // 0x1bcf3c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bcf3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1bcf40:
    // 0x1bcf40: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1bcf40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bcf44: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bcf44u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bcf48: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bcf48u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bcf4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BCF4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BCF50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCF4Cu;
            // 0x1bcf50: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BCD54u: goto label_1bcd54;
            case 0x1BCD5Cu: goto label_1bcd5c;
            case 0x1BCD64u: goto label_1bcd64;
            case 0x1BCD94u: goto label_1bcd94;
            case 0x1BCD9Cu: goto label_1bcd9c;
            case 0x1BCDD8u: goto label_1bcdd8;
            case 0x1BCDECu: goto label_1bcdec;
            case 0x1BCDF8u: goto label_1bcdf8;
            case 0x1BCE08u: goto label_1bce08;
            case 0x1BCE20u: goto label_1bce20;
            case 0x1BCE40u: goto label_1bce40;
            case 0x1BCE48u: goto label_1bce48;
            case 0x1BCE5Cu: goto label_1bce5c;
            case 0x1BCE74u: goto label_1bce74;
            case 0x1BCE90u: goto label_1bce90;
            case 0x1BCE98u: goto label_1bce98;
            case 0x1BCEA0u: goto label_1bcea0;
            case 0x1BCEB0u: goto label_1bceb0;
            case 0x1BCEB8u: goto label_1bceb8;
            case 0x1BCEC8u: goto label_1bcec8;
            case 0x1BCED0u: goto label_1bced0;
            case 0x1BCEE8u: goto label_1bcee8;
            case 0x1BCF04u: goto label_1bcf04;
            case 0x1BCF0Cu: goto label_1bcf0c;
            case 0x1BCF14u: goto label_1bcf14;
            case 0x1BCF24u: goto label_1bcf24;
            case 0x1BCF2Cu: goto label_1bcf2c;
            case 0x1BCF3Cu: goto label_1bcf3c;
            case 0x1BCF40u: goto label_1bcf40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BCF54u;
    // 0x1bcf54: 0x0  nop
    ctx->pc = 0x1bcf54u;
    // NOP
    // 0x1bcf58: 0x0  nop
    ctx->pc = 0x1bcf58u;
    // NOP
    // 0x1bcf5c: 0x0  nop
    ctx->pc = 0x1bcf5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
