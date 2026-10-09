#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001007C0
// Address: 0x1007c0 - 0x100838
void sub_001007C0_0x1007c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001007C0_0x1007c0");
#endif

    switch (ctx->pc) {
        case 0x1007e4u: goto label_1007e4;
        case 0x100800u: goto label_100800;
        case 0x100810u: goto label_100810;
        default: break;
    }

    ctx->pc = 0x1007c0u;

    // 0x1007c0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1007c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1007c4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1007c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1007c8: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1007c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1007cc: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x1007ccu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1007d0: 0x3c110020  lui         $s1, 0x20
    ctx->pc = 0x1007d0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32 << 16));
    // 0x1007d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1007d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1007d8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1007d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1007dc: 0xc047598  jal         func_11D660
    ctx->pc = 0x1007DCu;
    SET_GPR_U32(ctx, 31, 0x1007E4u);
    ctx->pc = 0x1007E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1007DCu;
            // 0x1007e0: 0xae327924  sw          $s2, 0x7924($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 31012), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1007E4u; }
        if (ctx->pc != 0x1007E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1007E4u; }
        if (ctx->pc != 0x1007E4u) { return; }
    }
    ctx->pc = 0x1007E4u;
label_1007e4:
    // 0x1007e4: 0x3c050010  lui         $a1, 0x10
    ctx->pc = 0x1007e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16 << 16));
    // 0x1007e8: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x1007e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x1007ec: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1007ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1007f0: 0x24a50768  addiu       $a1, $a1, 0x768
    ctx->pc = 0x1007f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1896));
    // 0x1007f4: 0x34840012  ori         $a0, $a0, 0x12
    ctx->pc = 0x1007f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)18);
    // 0x1007f8: 0xc045b02  jal         func_116C08
    ctx->pc = 0x1007F8u;
    SET_GPR_U32(ctx, 31, 0x100800u);
    ctx->pc = 0x1007FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1007F8u;
            // 0x1007fc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116C08u;
    if (runtime->hasFunction(0x116C08u)) {
        auto targetFn = runtime->lookupFunction(0x116C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100800u; }
        if (ctx->pc != 0x100800u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116C08_0x116c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100800u; }
        if (ctx->pc != 0x100800u) { return; }
    }
    ctx->pc = 0x100800u;
label_100800:
    // 0x100800: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x100800u;
    {
        const bool branch_taken_0x100800 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x100804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100800u;
            // 0x100804: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100800) {
            ctx->pc = 0x100814u;
            goto label_100814;
        }
    }
    ctx->pc = 0x100808u;
    // 0x100808: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x100808u;
    SET_GPR_U32(ctx, 31, 0x100810u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100810u; }
        if (ctx->pc != 0x100810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100810u; }
        if (ctx->pc != 0x100810u) { return; }
    }
    ctx->pc = 0x100810u;
label_100810:
    // 0x100810: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100810u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
label_100814:
    // 0x100814: 0xae207924  sw          $zero, 0x7924($s1)
    ctx->pc = 0x100814u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31012), GPR_U32(ctx, 0));
    // 0x100818: 0xac527940  sw          $s2, 0x7940($v0)
    ctx->pc = 0x100818u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31040), GPR_U32(ctx, 18));
    // 0x10081c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x10081cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x100820: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x100820u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x100824: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x100824u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100828: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x100828u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10082c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10082cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100830: 0x3e00008  jr          $ra
    ctx->pc = 0x100830u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100830u;
            // 0x100834: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1007E4u: goto label_1007e4;
            case 0x100800u: goto label_100800;
            case 0x100810u: goto label_100810;
            case 0x100814u: goto label_100814;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100838u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
