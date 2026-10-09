#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160140
// Address: 0x160140 - 0x160228
void sub_00160140_0x160140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160140_0x160140");
#endif

    switch (ctx->pc) {
        case 0x16015cu: goto label_16015c;
        default: break;
    }

    ctx->pc = 0x160140u;

    // 0x160140: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x160140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x160144: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x160144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160148: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x160148u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16014c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16014cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x160150: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x160150u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x160154: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x160154u;
    SET_GPR_U32(ctx, 31, 0x16015Cu);
    ctx->pc = 0x160158u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160154u;
            // 0x160158: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16015Cu; }
        if (ctx->pc != 0x16015Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16015Cu; }
        if (ctx->pc != 0x16015Cu) { return; }
    }
    ctx->pc = 0x16015Cu;
label_16015c:
    // 0x16015c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16015Cu;
    {
        const bool branch_taken_0x16015c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16015Cu;
            // 0x160160: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16015c) {
            ctx->pc = 0x160180u;
            goto label_160180;
        }
    }
    ctx->pc = 0x160164u;
    // 0x160164: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160164u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160168: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160168u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16016c: 0x2484f540  addiu       $a0, $a0, -0xAC0
    ctx->pc = 0x16016cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964544));
    // 0x160170: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x160170u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160174: 0x8058dd4  j           func_163750
    ctx->pc = 0x160174u;
    ctx->pc = 0x160178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160174u;
            // 0x160178: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16017Cu;
    // 0x16017c: 0x0  nop
    ctx->pc = 0x16017cu;
    // NOP
label_160180:
    // 0x160180: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x160180u;
    {
        const bool branch_taken_0x160180 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x160184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160180u;
            // 0x160184: 0x8e240040  lw          $a0, 0x40($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160180) {
            ctx->pc = 0x1601A8u;
            goto label_1601a8;
        }
    }
    ctx->pc = 0x160188u;
    // 0x160188: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160188u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16018c: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x16018cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x160190: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160190u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160194: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x160194u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160198: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x160198u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16019c: 0x805d4ce  j           func_175338
    ctx->pc = 0x16019Cu;
    ctx->pc = 0x1601A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16019Cu;
            // 0x1601a0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1601A4u;
    // 0x1601a4: 0x0  nop
    ctx->pc = 0x1601a4u;
    // NOP
label_1601a8:
    // 0x1601a8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1601a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1601ac: 0x16030008  bne         $s0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1601ACu;
    {
        const bool branch_taken_0x1601ac = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        ctx->pc = 0x1601B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1601ACu;
            // 0x1601b0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1601ac) {
            ctx->pc = 0x1601D0u;
            goto label_1601d0;
        }
    }
    ctx->pc = 0x1601B4u;
    // 0x1601b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1601b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1601b8: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x1601b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1601bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1601bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1601c0: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1601c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1601c4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1601c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1601c8: 0x805d4ce  j           func_175338
    ctx->pc = 0x1601C8u;
    ctx->pc = 0x1601CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1601C8u;
            // 0x1601cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1601D0u;
label_1601d0:
    // 0x1601d0: 0x16020011  bne         $s0, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1601D0u;
    {
        const bool branch_taken_0x1601d0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x1601D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1601D0u;
            // 0x1601d4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1601d0) {
            ctx->pc = 0x160218u;
            goto label_160218;
        }
    }
    ctx->pc = 0x1601D8u;
    // 0x1601d8: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x1601d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1601dc: 0x14430008  bne         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1601DCu;
    {
        const bool branch_taken_0x1601dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1601E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1601DCu;
            // 0x1601e0: 0x2405000f  addiu       $a1, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1601dc) {
            ctx->pc = 0x160200u;
            goto label_160200;
        }
    }
    ctx->pc = 0x1601E4u;
    // 0x1601e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1601e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1601e8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1601e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1601ec: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1601ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1601f0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1601f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1601f4: 0x805d4ce  j           func_175338
    ctx->pc = 0x1601F4u;
    ctx->pc = 0x1601F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1601F4u;
            // 0x1601f8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1601FCu;
    // 0x1601fc: 0x0  nop
    ctx->pc = 0x1601fcu;
    // NOP
label_160200:
    // 0x160200: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160200u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160204: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x160204u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x160208: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x160208u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16020c: 0x805d4ce  j           func_175338
    ctx->pc = 0x16020Cu;
    ctx->pc = 0x160210u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16020Cu;
            // 0x160210: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160214u;
    // 0x160214: 0x0  nop
    ctx->pc = 0x160214u;
    // NOP
label_160218:
    // 0x160218: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160218u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16021c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16021cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160220: 0x3e00008  jr          $ra
    ctx->pc = 0x160220u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160220u;
            // 0x160224: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16015Cu: goto label_16015c;
            case 0x160180u: goto label_160180;
            case 0x1601A8u: goto label_1601a8;
            case 0x1601D0u: goto label_1601d0;
            case 0x160200u: goto label_160200;
            case 0x160218u: goto label_160218;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160228u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
