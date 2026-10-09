#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164450
// Address: 0x164450 - 0x1644f0
void sub_00164450_0x164450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164450_0x164450");
#endif

    switch (ctx->pc) {
        case 0x164474u: goto label_164474;
        case 0x164494u: goto label_164494;
        case 0x1644a0u: goto label_1644a0;
        case 0x1644b8u: goto label_1644b8;
        case 0x1644d8u: goto label_1644d8;
        default: break;
    }

    ctx->pc = 0x164450u;

    // 0x164450: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x164450u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x164454: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x164454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x164458: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x164458u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16445c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16445cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x164460: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x164460u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164464: 0x14c00006  bnez        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x164464u;
    {
        const bool branch_taken_0x164464 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x164468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164464u;
            // 0x164468: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164464) {
            ctx->pc = 0x164480u;
            goto label_164480;
        }
    }
    ctx->pc = 0x16446Cu;
    // 0x16446c: 0xc04c170  jal         func_1305C0
    ctx->pc = 0x16446Cu;
    SET_GPR_U32(ctx, 31, 0x164474u);
    ctx->pc = 0x1305C0u;
    if (runtime->hasFunction(0x1305C0u)) {
        auto targetFn = runtime->lookupFunction(0x1305C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164474u; }
        if (ctx->pc != 0x164474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305C0_0x1305c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164474u; }
        if (ctx->pc != 0x164474u) { return; }
    }
    ctx->pc = 0x164474u;
label_164474:
    // 0x164474: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x164474u;
    {
        const bool branch_taken_0x164474 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x164478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164474u;
            // 0x164478: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164474) {
            ctx->pc = 0x1644DCu;
            goto label_1644dc;
        }
    }
    ctx->pc = 0x16447Cu;
    // 0x16447c: 0x0  nop
    ctx->pc = 0x16447cu;
    // NOP
label_164480:
    // 0x164480: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x164480u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x164484: 0x54c20008  bnel        $a2, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x164484u;
    {
        const bool branch_taken_0x164484 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x164484) {
            ctx->pc = 0x164488u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164484u;
            // 0x164488: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1644A8u;
            goto label_1644a8;
        }
    }
    ctx->pc = 0x16448Cu;
    // 0x16448c: 0xc04c182  jal         func_130608
    ctx->pc = 0x16448Cu;
    SET_GPR_U32(ctx, 31, 0x164494u);
    ctx->pc = 0x130608u;
    if (runtime->hasFunction(0x130608u)) {
        auto targetFn = runtime->lookupFunction(0x130608u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164494u; }
        if (ctx->pc != 0x164494u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130608_0x130608(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164494u; }
        if (ctx->pc != 0x164494u) { return; }
    }
    ctx->pc = 0x164494u;
label_164494:
    // 0x164494: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x164494u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164498: 0xc04c170  jal         func_1305C0
    ctx->pc = 0x164498u;
    SET_GPR_U32(ctx, 31, 0x1644A0u);
    ctx->pc = 0x16449Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164498u;
            // 0x16449c: 0x512821  addu        $a1, $v0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305C0u;
    if (runtime->hasFunction(0x1305C0u)) {
        auto targetFn = runtime->lookupFunction(0x1305C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1644A0u; }
        if (ctx->pc != 0x1644A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305C0_0x1305c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1644A0u; }
        if (ctx->pc != 0x1644A0u) { return; }
    }
    ctx->pc = 0x1644A0u;
label_1644a0:
    // 0x1644a0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1644A0u;
    {
        const bool branch_taken_0x1644a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1644A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1644A0u;
            // 0x1644a4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1644a0) {
            ctx->pc = 0x1644DCu;
            goto label_1644dc;
        }
    }
    ctx->pc = 0x1644A8u;
label_1644a8:
    // 0x1644a8: 0x54c2000c  bnel        $a2, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1644A8u;
    {
        const bool branch_taken_0x1644a8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x1644a8) {
            ctx->pc = 0x1644ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1644A8u;
            // 0x1644ac: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1644DCu;
            goto label_1644dc;
        }
    }
    ctx->pc = 0x1644B0u;
    // 0x1644b0: 0xc04c390  jal         func_130E40
    ctx->pc = 0x1644B0u;
    SET_GPR_U32(ctx, 31, 0x1644B8u);
    ctx->pc = 0x130E40u;
    if (runtime->hasFunction(0x130E40u)) {
        auto targetFn = runtime->lookupFunction(0x130E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1644B8u; }
        if (ctx->pc != 0x1644B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130E40_0x130e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1644B8u; }
        if (ctx->pc != 0x1644B8u) { return; }
    }
    ctx->pc = 0x1644B8u;
label_1644b8:
    // 0x1644b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1644b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1644bc: 0x244507ff  addiu       $a1, $v0, 0x7FF
    ctx->pc = 0x1644bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x1644c0: 0x24420ffe  addiu       $v0, $v0, 0xFFE
    ctx->pc = 0x1644c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4094));
    // 0x1644c4: 0x28a30000  slti        $v1, $a1, 0x0
    ctx->pc = 0x1644c4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1644c8: 0x43280b  movn        $a1, $v0, $v1
    ctx->pc = 0x1644c8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
    // 0x1644cc: 0x52ac3  sra         $a1, $a1, 11
    ctx->pc = 0x1644ccu;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 11));
    // 0x1644d0: 0xc04c170  jal         func_1305C0
    ctx->pc = 0x1644D0u;
    SET_GPR_U32(ctx, 31, 0x1644D8u);
    ctx->pc = 0x1644D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1644D0u;
            // 0x1644d4: 0xb12821  addu        $a1, $a1, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305C0u;
    if (runtime->hasFunction(0x1305C0u)) {
        auto targetFn = runtime->lookupFunction(0x1305C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1644D8u; }
        if (ctx->pc != 0x1644D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305C0_0x1305c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1644D8u; }
        if (ctx->pc != 0x1644D8u) { return; }
    }
    ctx->pc = 0x1644D8u;
label_1644d8:
    // 0x1644d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1644d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1644dc:
    // 0x1644dc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1644dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1644e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1644e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1644e4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1644e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1644e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1644E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1644ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1644E8u;
            // 0x1644ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164474u: goto label_164474;
            case 0x164480u: goto label_164480;
            case 0x164494u: goto label_164494;
            case 0x1644A0u: goto label_1644a0;
            case 0x1644A8u: goto label_1644a8;
            case 0x1644B8u: goto label_1644b8;
            case 0x1644D8u: goto label_1644d8;
            case 0x1644DCu: goto label_1644dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1644F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
