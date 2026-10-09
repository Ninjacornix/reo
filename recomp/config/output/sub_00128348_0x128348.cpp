#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128348
// Address: 0x128348 - 0x128410
void sub_00128348_0x128348(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128348_0x128348");
#endif

    switch (ctx->pc) {
        case 0x128388u: goto label_128388;
        case 0x12839cu: goto label_12839c;
        case 0x1283b0u: goto label_1283b0;
        case 0x1283c4u: goto label_1283c4;
        default: break;
    }

    ctx->pc = 0x128348u;

    // 0x128348: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x128348u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12834c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12834cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x128350: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x128350u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x128354: 0x2450c8bc  addiu       $s0, $v0, -0x3744
    ctx->pc = 0x128354u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953148));
    // 0x128358: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x128358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12835c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12835cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x128360: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x128360u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x128364: 0x2463c8b8  addiu       $v1, $v1, -0x3748
    ctx->pc = 0x128364u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294953144));
    // 0x128368: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x128368u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12836c: 0x14800022  bnez        $a0, . + 4 + (0x22 << 2)
    ctx->pc = 0x12836Cu;
    {
        const bool branch_taken_0x12836c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x128370u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12836Cu;
            // 0x128370: 0x24820001  addiu       $v0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12836c) {
            ctx->pc = 0x1283F8u;
            goto label_1283f8;
        }
    }
    ctx->pc = 0x128374u;
    // 0x128374: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x128374u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x128378: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x128378u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12837c: 0x2484c8c0  addiu       $a0, $a0, -0x3740
    ctx->pc = 0x12837cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953152));
    // 0x128380: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x128380u;
    SET_GPR_U32(ctx, 31, 0x128388u);
    ctx->pc = 0x128384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128380u;
            // 0x128384: 0x24060440  addiu       $a2, $zero, 0x440 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1088));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128388u; }
        if (ctx->pc != 0x128388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128388u; }
        if (ctx->pc != 0x128388u) { return; }
    }
    ctx->pc = 0x128388u;
label_128388:
    // 0x128388: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x128388u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12838c: 0x2484cd00  addiu       $a0, $a0, -0x3300
    ctx->pc = 0x12838cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954240));
    // 0x128390: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x128390u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128394: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x128394u;
    SET_GPR_U32(ctx, 31, 0x12839Cu);
    ctx->pc = 0x128398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128394u;
            // 0x128398: 0x24060400  addiu       $a2, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12839Cu; }
        if (ctx->pc != 0x12839Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12839Cu; }
        if (ctx->pc != 0x12839Cu) { return; }
    }
    ctx->pc = 0x12839Cu;
label_12839c:
    // 0x12839c: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12839cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x1283a0: 0x2484d108  addiu       $a0, $a0, -0x2EF8
    ctx->pc = 0x1283a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955272));
    // 0x1283a4: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1283a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1283a8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1283A8u;
    SET_GPR_U32(ctx, 31, 0x1283B0u);
    ctx->pc = 0x1283ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1283A8u;
            // 0x1283ac: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1283B0u; }
        if (ctx->pc != 0x1283B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1283B0u; }
        if (ctx->pc != 0x1283B0u) { return; }
    }
    ctx->pc = 0x1283B0u;
label_1283b0:
    // 0x1283b0: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x1283b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x1283b4: 0x2484d208  addiu       $a0, $a0, -0x2DF8
    ctx->pc = 0x1283b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955528));
    // 0x1283b8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1283b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1283bc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1283BCu;
    SET_GPR_U32(ctx, 31, 0x1283C4u);
    ctx->pc = 0x1283C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1283BCu;
            // 0x1283c0: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1283C4u; }
        if (ctx->pc != 0x1283C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1283C4u; }
        if (ctx->pc != 0x1283C4u) { return; }
    }
    ctx->pc = 0x1283C4u;
label_1283c4:
    // 0x1283c4: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x1283c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x1283c8: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x1283c8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x1283cc: 0x3c060021  lui         $a2, 0x21
    ctx->pc = 0x1283ccu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)33 << 16));
    // 0x1283d0: 0x3c070021  lui         $a3, 0x21
    ctx->pc = 0x1283d0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)33 << 16));
    // 0x1283d4: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x1283d4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x1283d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1283d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1283dc: 0xac80d228  sw          $zero, -0x2DD8($a0)
    ctx->pc = 0x1283dcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4294955560), GPR_U32(ctx, 0));
    // 0x1283e0: 0xac62d234  sw          $v0, -0x2DCC($v1)
    ctx->pc = 0x1283e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294955572), GPR_U32(ctx, 2));
    // 0x1283e4: 0xaca0d100  sw          $zero, -0x2F00($a1)
    ctx->pc = 0x1283e4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294955264), GPR_U32(ctx, 0));
    // 0x1283e8: 0xacc0d22c  sw          $zero, -0x2DD4($a2)
    ctx->pc = 0x1283e8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4294955564), GPR_U32(ctx, 0));
    // 0x1283ec: 0xace0d230  sw          $zero, -0x2DD0($a3)
    ctx->pc = 0x1283ecu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294955568), GPR_U32(ctx, 0));
    // 0x1283f0: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1283f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1283f4: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1283f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_1283f8:
    // 0x1283f8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1283f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1283fc: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1283fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x128400: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x128400u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128404: 0x3e00008  jr          $ra
    ctx->pc = 0x128404u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128404u;
            // 0x128408: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128388u: goto label_128388;
            case 0x12839Cu: goto label_12839c;
            case 0x1283B0u: goto label_1283b0;
            case 0x1283C4u: goto label_1283c4;
            case 0x1283F8u: goto label_1283f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12840Cu;
    // 0x12840c: 0x0  nop
    ctx->pc = 0x12840cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
