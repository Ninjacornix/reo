#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B790
// Address: 0x13b790 - 0x13b83c
void sub_0013B790_0x13b790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B790_0x13b790");
#endif

    switch (ctx->pc) {
        case 0x13b7c0u: goto label_13b7c0;
        case 0x13b7d4u: goto label_13b7d4;
        case 0x13b7dcu: goto label_13b7dc;
        case 0x13b7e8u: goto label_13b7e8;
        case 0x13b80cu: goto label_13b80c;
        default: break;
    }

    ctx->pc = 0x13b790u;

    // 0x13b790: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13b790u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13b794: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13b794u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13b798: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13b798u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b79c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13b79cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13b7a0: 0x12200021  beqz        $s1, . + 4 + (0x21 << 2)
    ctx->pc = 0x13B7A0u;
    {
        const bool branch_taken_0x13b7a0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B7A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B7A0u;
            // 0x13b7a4: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b7a0) {
            ctx->pc = 0x13B828u;
            goto label_13b828;
        }
    }
    ctx->pc = 0x13B7A8u;
    // 0x13b7a8: 0x92220002  lbu         $v0, 0x2($s1)
    ctx->pc = 0x13b7a8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x13b7ac: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x13b7acu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x13b7b0: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x13B7B0u;
    {
        const bool branch_taken_0x13b7b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13b7b0) {
            ctx->pc = 0x13B7B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13B7B0u;
            // 0x13b7b4: 0x82220001  lb          $v0, 0x1($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13B7C4u;
            goto label_13b7c4;
        }
    }
    ctx->pc = 0x13B7B8u;
    // 0x13b7b8: 0xc04eea8  jal         func_13BAA0
    ctx->pc = 0x13B7B8u;
    SET_GPR_U32(ctx, 31, 0x13B7C0u);
    ctx->pc = 0x13BAA0u;
    if (runtime->hasFunction(0x13BAA0u)) {
        auto targetFn = runtime->lookupFunction(0x13BAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B7C0u; }
        if (ctx->pc != 0x13B7C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BAA0_0x13baa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B7C0u; }
        if (ctx->pc != 0x13B7C0u) { return; }
    }
    ctx->pc = 0x13B7C0u;
label_13b7c0:
    // 0x13b7c0: 0x82220001  lb          $v0, 0x1($s1)
    ctx->pc = 0x13b7c0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
label_13b7c4:
    // 0x13b7c4: 0x54400012  bnel        $v0, $zero, . + 4 + (0x12 << 2)
    ctx->pc = 0x13B7C4u;
    {
        const bool branch_taken_0x13b7c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13b7c4) {
            ctx->pc = 0x13B7C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13B7C4u;
            // 0x13b7c8: 0xa2200000  sb          $zero, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13B810u;
            goto label_13b810;
        }
    }
    ctx->pc = 0x13B7CCu;
    // 0x13b7cc: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B7CCu;
    SET_GPR_U32(ctx, 31, 0x13B7D4u);
    ctx->pc = 0x13B7D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B7CCu;
            // 0x13b7d0: 0x24045000  addiu       $a0, $zero, 0x5000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B7D4u; }
        if (ctx->pc != 0x13B7D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B7D4u; }
        if (ctx->pc != 0x13B7D4u) { return; }
    }
    ctx->pc = 0x13B7D4u;
label_13b7d4:
    // 0x13b7d4: 0xc04e160  jal         func_138580
    ctx->pc = 0x13B7D4u;
    SET_GPR_U32(ctx, 31, 0x13B7DCu);
    ctx->pc = 0x13B7D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B7D4u;
            // 0x13b7d8: 0x8e240018  lw          $a0, 0x18($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138580u;
    if (runtime->hasFunction(0x138580u)) {
        auto targetFn = runtime->lookupFunction(0x138580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B7DCu; }
        if (ctx->pc != 0x13B7DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138580_0x138580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B7DCu; }
        if (ctx->pc != 0x13B7DCu) { return; }
    }
    ctx->pc = 0x13B7DCu;
label_13b7dc:
    // 0x13b7dc: 0x24045001  addiu       $a0, $zero, 0x5001
    ctx->pc = 0x13b7dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20481));
    // 0x13b7e0: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B7E0u;
    SET_GPR_U32(ctx, 31, 0x13B7E8u);
    ctx->pc = 0x13B7E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B7E0u;
            // 0x13b7e4: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B7E8u; }
        if (ctx->pc != 0x13B7E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B7E8u; }
        if (ctx->pc != 0x13B7E8u) { return; }
    }
    ctx->pc = 0x13B7E8u;
label_13b7e8:
    // 0x13b7e8: 0x6030009  bgezl       $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13B7E8u;
    {
        const bool branch_taken_0x13b7e8 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x13b7e8) {
            ctx->pc = 0x13B7ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13B7E8u;
            // 0x13b7ec: 0xa2200000  sb          $zero, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13B810u;
            goto label_13b810;
        }
    }
    ctx->pc = 0x13B7F0u;
    // 0x13b7f0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b7f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b7f4: 0x8c43dea4  lw          $v1, -0x215C($v0)
    ctx->pc = 0x13b7f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958756)));
    // 0x13b7f8: 0x54600005  bnel        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x13B7F8u;
    {
        const bool branch_taken_0x13b7f8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x13b7f8) {
            ctx->pc = 0x13B7FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13B7F8u;
            // 0x13b7fc: 0xa2200000  sb          $zero, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13B810u;
            goto label_13b810;
        }
    }
    ctx->pc = 0x13B800u;
    // 0x13b800: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13b800u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13b804: 0xc045a12  jal         func_116848
    ctx->pc = 0x13B804u;
    SET_GPR_U32(ctx, 31, 0x13B80Cu);
    ctx->pc = 0x13B808u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B804u;
            // 0x13b808: 0x2484d098  addiu       $a0, $a0, -0x2F68 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B80Cu; }
        if (ctx->pc != 0x13B80Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B80Cu; }
        if (ctx->pc != 0x13B80Cu) { return; }
    }
    ctx->pc = 0x13B80Cu;
label_13b80c:
    // 0x13b80c: 0xa2200000  sb          $zero, 0x0($s1)
    ctx->pc = 0x13b80cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
label_13b810:
    // 0x13b810: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13b810u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b814: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13b814u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13b818: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13b818u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13b81c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13b81cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13b820: 0x804ed7a  j           func_13B5E8
    ctx->pc = 0x13B820u;
    ctx->pc = 0x13B824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B820u;
            // 0x13b824: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13B5E8u;
    if (runtime->hasFunction(0x13B5E8u)) {
        auto targetFn = runtime->lookupFunction(0x13B5E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013B5E8_0x13b5e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13B828u;
label_13b828:
    // 0x13b828: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13b828u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13b82c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13b82cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13b830: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13b830u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13b834: 0x3e00008  jr          $ra
    ctx->pc = 0x13B834u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B834u;
            // 0x13b838: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B7C0u: goto label_13b7c0;
            case 0x13B7C4u: goto label_13b7c4;
            case 0x13B7D4u: goto label_13b7d4;
            case 0x13B7DCu: goto label_13b7dc;
            case 0x13B7E8u: goto label_13b7e8;
            case 0x13B80Cu: goto label_13b80c;
            case 0x13B810u: goto label_13b810;
            case 0x13B828u: goto label_13b828;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B83Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
