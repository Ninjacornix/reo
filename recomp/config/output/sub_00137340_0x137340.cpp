#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137340
// Address: 0x137340 - 0x1373c8
void sub_00137340_0x137340(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137340_0x137340");
#endif

    switch (ctx->pc) {
        case 0x137358u: goto label_137358;
        case 0x137374u: goto label_137374;
        case 0x1373acu: goto label_1373ac;
        default: break;
    }

    ctx->pc = 0x137340u;

    // 0x137340: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x137340u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x137344: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x137344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x137348: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x137348u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13734c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13734cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x137350: 0xc0505c0  jal         func_141700
    ctx->pc = 0x137350u;
    SET_GPR_U32(ctx, 31, 0x137358u);
    ctx->pc = 0x137354u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137350u;
            // 0x137354: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141700u;
    if (runtime->hasFunction(0x141700u)) {
        auto targetFn = runtime->lookupFunction(0x141700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137358u; }
        if (ctx->pc != 0x137358u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141700_0x141700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137358u; }
        if (ctx->pc != 0x137358u) { return; }
    }
    ctx->pc = 0x137358u;
label_137358:
    // 0x137358: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x137358u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13735c: 0x2450bb88  addiu       $s0, $v0, -0x4478
    ctx->pc = 0x13735cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949768));
    // 0x137360: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x137360u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x137364: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x137364u;
    {
        const bool branch_taken_0x137364 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x137364) {
            ctx->pc = 0x1373A4u;
            goto label_1373a4;
        }
    }
    ctx->pc = 0x13736Cu;
    // 0x13736c: 0xc04dcc4  jal         func_137310
    ctx->pc = 0x13736Cu;
    SET_GPR_U32(ctx, 31, 0x137374u);
    ctx->pc = 0x137310u;
    if (runtime->hasFunction(0x137310u)) {
        auto targetFn = runtime->lookupFunction(0x137310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137374u; }
        if (ctx->pc != 0x137374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137310_0x137310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137374u; }
        if (ctx->pc != 0x137374u) { return; }
    }
    ctx->pc = 0x137374u;
label_137374:
    // 0x137374: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x137374u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137378: 0xa2040000  sb          $a0, 0x0($s0)
    ctx->pc = 0x137378u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x13737c: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13737cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137380: 0x2463bbe8  addiu       $v1, $v1, -0x4418
    ctx->pc = 0x137380u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949864));
    // 0x137384: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x137384u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x137388: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x137388u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13738c: 0x200882d  daddu       $s1, $s0, $zero
    ctx->pc = 0x13738cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137390: 0xa2050003  sb          $a1, 0x3($s0)
    ctx->pc = 0x137390u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 5));
    // 0x137394: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x137394u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x137398: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x137398u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x13739c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x13739cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1373a0: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1373a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
label_1373a4:
    // 0x1373a4: 0xc0505de  jal         func_141778
    ctx->pc = 0x1373A4u;
    SET_GPR_U32(ctx, 31, 0x1373ACu);
    ctx->pc = 0x141778u;
    if (runtime->hasFunction(0x141778u)) {
        auto targetFn = runtime->lookupFunction(0x141778u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1373ACu; }
        if (ctx->pc != 0x1373ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141778_0x141778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1373ACu; }
        if (ctx->pc != 0x1373ACu) { return; }
    }
    ctx->pc = 0x1373ACu;
label_1373ac:
    // 0x1373ac: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1373acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1373b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1373b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1373b4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1373b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1373b8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1373b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1373bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1373BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1373C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1373BCu;
            // 0x1373c0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137358u: goto label_137358;
            case 0x137374u: goto label_137374;
            case 0x1373A4u: goto label_1373a4;
            case 0x1373ACu: goto label_1373ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1373C4u;
    // 0x1373c4: 0x0  nop
    ctx->pc = 0x1373c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
