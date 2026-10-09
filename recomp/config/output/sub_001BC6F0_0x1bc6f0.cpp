#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC6F0
// Address: 0x1bc6f0 - 0x1bc780
void sub_001BC6F0_0x1bc6f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC6F0_0x1bc6f0");
#endif

    switch (ctx->pc) {
        case 0x1bc710u: goto label_1bc710;
        case 0x1bc720u: goto label_1bc720;
        case 0x1bc728u: goto label_1bc728;
        case 0x1bc738u: goto label_1bc738;
        case 0x1bc748u: goto label_1bc748;
        case 0x1bc750u: goto label_1bc750;
        default: break;
    }

    ctx->pc = 0x1bc6f0u;

    // 0x1bc6f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bc6f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bc6f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bc6f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bc6f8: 0x90820008  lbu         $v0, 0x8($a0)
    ctx->pc = 0x1bc6f8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1bc6fc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bc6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bc700: 0xa0820008  sb          $v0, 0x8($a0)
    ctx->pc = 0x1bc700u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 8), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bc704: 0xa0800009  sb          $zero, 0x9($a0)
    ctx->pc = 0x1bc704u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 9), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bc708: 0xc06a568  jal         func_1A95A0
    ctx->pc = 0x1BC708u;
    SET_GPR_U32(ctx, 31, 0x1BC710u);
    ctx->pc = 0x1BC70Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC708u;
            // 0x1bc70c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A95A0u;
    if (runtime->hasFunction(0x1A95A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A95A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC710u; }
        if (ctx->pc != 0x1BC710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A95A0_0x1a95a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC710u; }
        if (ctx->pc != 0x1BC710u) { return; }
    }
    ctx->pc = 0x1BC710u;
label_1bc710:
    // 0x1bc710: 0x3c05001c  lui         $a1, 0x1C
    ctx->pc = 0x1bc710u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28 << 16));
    // 0x1bc714: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1bc714u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bc718: 0xc06e02c  jal         func_1B80B0
    ctx->pc = 0x1BC718u;
    SET_GPR_U32(ctx, 31, 0x1BC720u);
    ctx->pc = 0x1BC71Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC718u;
            // 0x1bc71c: 0x24a5cd20  addiu       $a1, $a1, -0x32E0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80B0u;
    if (runtime->hasFunction(0x1B80B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B80B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC720u; }
        if (ctx->pc != 0x1BC720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B80B0_0x1b80b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC720u; }
        if (ctx->pc != 0x1BC720u) { return; }
    }
    ctx->pc = 0x1BC720u;
label_1bc720:
    // 0x1bc720: 0xc06fd60  jal         func_1BF580
    ctx->pc = 0x1BC720u;
    SET_GPR_U32(ctx, 31, 0x1BC728u);
    ctx->pc = 0x1BF580u;
    if (runtime->hasFunction(0x1BF580u)) {
        auto targetFn = runtime->lookupFunction(0x1BF580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC728u; }
        if (ctx->pc != 0x1BC728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF580_0x1bf580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC728u; }
        if (ctx->pc != 0x1BC728u) { return; }
    }
    ctx->pc = 0x1BC728u;
label_1bc728:
    // 0x1bc728: 0x3c04001c  lui         $a0, 0x1C
    ctx->pc = 0x1bc728u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28 << 16));
    // 0x1bc72c: 0x2405000e  addiu       $a1, $zero, 0xE
    ctx->pc = 0x1bc72cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1bc730: 0xc06dfb8  jal         func_1B7EE0
    ctx->pc = 0x1BC730u;
    SET_GPR_U32(ctx, 31, 0x1BC738u);
    ctx->pc = 0x1BC734u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC730u;
            // 0x1bc734: 0x2484a680  addiu       $a0, $a0, -0x5980 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294944384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7EE0u;
    if (runtime->hasFunction(0x1B7EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1B7EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC738u; }
        if (ctx->pc != 0x1BC738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7EE0_0x1b7ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC738u; }
        if (ctx->pc != 0x1BC738u) { return; }
    }
    ctx->pc = 0x1BC738u;
label_1bc738:
    // 0x1bc738: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bc738u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bc73c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bc73cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bc740: 0xc06cf64  jal         func_1B3D90
    ctx->pc = 0x1BC740u;
    SET_GPR_U32(ctx, 31, 0x1BC748u);
    ctx->pc = 0x1BC744u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC740u;
            // 0x1bc744: 0xa02241f0  sb          $v0, 0x41F0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 16880), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3D90u;
    if (runtime->hasFunction(0x1B3D90u)) {
        auto targetFn = runtime->lookupFunction(0x1B3D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC748u; }
        if (ctx->pc != 0x1BC748u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3D90_0x1b3d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC748u; }
        if (ctx->pc != 0x1BC748u) { return; }
    }
    ctx->pc = 0x1BC748u;
label_1bc748:
    // 0x1bc748: 0xc074ee4  jal         func_1D3B90
    ctx->pc = 0x1BC748u;
    SET_GPR_U32(ctx, 31, 0x1BC750u);
    ctx->pc = 0x1D3B90u;
    if (runtime->hasFunction(0x1D3B90u)) {
        auto targetFn = runtime->lookupFunction(0x1D3B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC750u; }
        if (ctx->pc != 0x1BC750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3B90_0x1d3b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC750u; }
        if (ctx->pc != 0x1BC750u) { return; }
    }
    ctx->pc = 0x1BC750u;
label_1bc750:
    // 0x1bc750: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bc750u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bc754: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bc754u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bc758: 0x902443c3  lbu         $a0, 0x43C3($at)
    ctx->pc = 0x1bc758u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17347)));
    // 0x1bc75c: 0x14830003  bne         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BC75Cu;
    {
        const bool branch_taken_0x1bc75c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1BC760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC75Cu;
            // 0x1bc760: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc75c) {
            ctx->pc = 0x1BC76Cu;
            goto label_1bc76c;
        }
    }
    ctx->pc = 0x1BC764u;
    // 0x1bc764: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bc764u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bc768: 0xa023448e  sb          $v1, 0x448E($at)
    ctx->pc = 0x1bc768u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17550), (uint8_t)GPR_U32(ctx, 3));
label_1bc76c:
    // 0x1bc76c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bc76cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bc770: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC770u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BC774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC770u;
            // 0x1bc774: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BC710u: goto label_1bc710;
            case 0x1BC720u: goto label_1bc720;
            case 0x1BC728u: goto label_1bc728;
            case 0x1BC738u: goto label_1bc738;
            case 0x1BC748u: goto label_1bc748;
            case 0x1BC750u: goto label_1bc750;
            case 0x1BC76Cu: goto label_1bc76c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BC778u;
    // 0x1bc778: 0x0  nop
    ctx->pc = 0x1bc778u;
    // NOP
    // 0x1bc77c: 0x0  nop
    ctx->pc = 0x1bc77cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
