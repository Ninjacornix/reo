#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A968
// Address: 0x12a968 - 0x12a9ec
void sub_0012A968_0x12a968(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A968_0x12a968");
#endif

    switch (ctx->pc) {
        case 0x12a994u: goto label_12a994;
        case 0x12a9acu: goto label_12a9ac;
        case 0x12a9c4u: goto label_12a9c4;
        default: break;
    }

    ctx->pc = 0x12a968u;

    // 0x12a968: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12a968u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12a96c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12a96cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12a970: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12a970u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12a974: 0x24520480  addiu       $s2, $v0, 0x480
    ctx->pc = 0x12a974u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 1152));
    // 0x12a978: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x12a978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x12a97c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12a97cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12a980: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12a980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12a984: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x12A984u;
    {
        const bool branch_taken_0x12a984 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12A988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A984u;
            // 0x12a988: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a984) {
            ctx->pc = 0x12A9CCu;
            goto label_12a9cc;
        }
    }
    ctx->pc = 0x12A98Cu;
    // 0x12a98c: 0xc045144  jal         func_114510
    ctx->pc = 0x12A98Cu;
    SET_GPR_U32(ctx, 31, 0x12A994u);
    ctx->pc = 0x12A990u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A98Cu;
            // 0x12a990: 0x3c100021  lui         $s0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A994u; }
        if (ctx->pc != 0x12A994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A994u; }
        if (ctx->pc != 0x12A994u) { return; }
    }
    ctx->pc = 0x12A994u;
label_12a994:
    // 0x12a994: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12a994u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a998: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12a998u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12a99c: 0x8c450460  lw          $a1, 0x460($v0)
    ctx->pc = 0x12a99cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1120)));
    // 0x12a9a0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12a9a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a9a4: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12A9A4u;
    SET_GPR_U32(ctx, 31, 0x12A9ACu);
    ctx->pc = 0x12A9A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A9A4u;
            // 0x12a9a8: 0x261004d8  addiu       $s0, $s0, 0x4D8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A9ACu; }
        if (ctx->pc != 0x12A9ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A9ACu; }
        if (ctx->pc != 0x12A9ACu) { return; }
    }
    ctx->pc = 0x12A9ACu;
label_12a9ac:
    // 0x12a9ac: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12a9acu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12a9b0: 0xac627d70  sw          $v0, 0x7D70($v1)
    ctx->pc = 0x12a9b0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 32112), GPR_U32(ctx, 2));
    // 0x12a9b4: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x12a9b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x12a9b8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12a9b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12a9bc: 0xc04ac3c  jal         func_12B0F0
    ctx->pc = 0x12A9BCu;
    SET_GPR_U32(ctx, 31, 0x12A9C4u);
    ctx->pc = 0x12A9C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A9BCu;
            // 0x12a9c0: 0xacb17d74  sw          $s1, 0x7D74($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 32116), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B0F0u;
    if (runtime->hasFunction(0x12B0F0u)) {
        auto targetFn = runtime->lookupFunction(0x12B0F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A9C4u; }
        if (ctx->pc != 0x12A9C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0F0_0x12b0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A9C4u; }
        if (ctx->pc != 0x12A9C4u) { return; }
    }
    ctx->pc = 0x12A9C4u;
label_12a9c4:
    // 0x12a9c4: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x12a9c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12a9c8: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x12a9c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_12a9cc:
    // 0x12a9cc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12a9ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12a9d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12a9d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a9d4: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x12a9d4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x12a9d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12a9d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a9dc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12a9dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12a9e0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12a9e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12a9e4: 0x3e00008  jr          $ra
    ctx->pc = 0x12A9E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A9E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A9E4u;
            // 0x12a9e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A994u: goto label_12a994;
            case 0x12A9ACu: goto label_12a9ac;
            case 0x12A9C4u: goto label_12a9c4;
            case 0x12A9CCu: goto label_12a9cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A9ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
