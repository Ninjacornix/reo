#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166098
// Address: 0x166098 - 0x166124
void sub_00166098_0x166098(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166098_0x166098");
#endif

    switch (ctx->pc) {
        case 0x1660b0u: goto label_1660b0;
        case 0x1660ecu: goto label_1660ec;
        case 0x1660f8u: goto label_1660f8;
        default: break;
    }

    ctx->pc = 0x166098u;

    // 0x166098: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166098u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16609c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16609cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1660a0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1660a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1660a4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1660a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1660a8: 0xc05984a  jal         func_166128
    ctx->pc = 0x1660A8u;
    SET_GPR_U32(ctx, 31, 0x1660B0u);
    ctx->pc = 0x1660ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1660A8u;
            // 0x1660ac: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166128u;
    if (runtime->hasFunction(0x166128u)) {
        auto targetFn = runtime->lookupFunction(0x166128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660B0u; }
        if (ctx->pc != 0x1660B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166128_0x166128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660B0u; }
        if (ctx->pc != 0x1660B0u) { return; }
    }
    ctx->pc = 0x1660B0u;
label_1660b0:
    // 0x1660b0: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1660b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1660b4: 0x50c00017  beql        $a2, $zero, . + 4 + (0x17 << 2)
    ctx->pc = 0x1660B4u;
    {
        const bool branch_taken_0x1660b4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1660b4) {
            ctx->pc = 0x1660B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1660B4u;
            // 0x1660b8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x166114u;
            goto label_166114;
        }
    }
    ctx->pc = 0x1660BCu;
    // 0x1660bc: 0x8e101b74  lw          $s0, 0x1B74($s0)
    ctx->pc = 0x1660bcu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7028)));
    // 0x1660c0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1660c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1660c4: 0x8e030034  lw          $v1, 0x34($s0)
    ctx->pc = 0x1660c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1660c8: 0x14600011  bnez        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1660C8u;
    {
        const bool branch_taken_0x1660c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1660CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1660C8u;
            // 0x1660cc: 0x8e110000  lw          $s1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1660c8) {
            ctx->pc = 0x166110u;
            goto label_166110;
        }
    }
    ctx->pc = 0x1660D0u;
    // 0x1660d0: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x1660d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1660d4: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1660D4u;
    {
        const bool branch_taken_0x1660d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1660D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1660D4u;
            // 0x1660d8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1660d4) {
            ctx->pc = 0x166110u;
            goto label_166110;
        }
    }
    ctx->pc = 0x1660DCu;
    // 0x1660dc: 0x8cc70014  lw          $a3, 0x14($a2)
    ctx->pc = 0x1660dcu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 20)));
    // 0x1660e0: 0x8cc5000c  lw          $a1, 0xC($a2)
    ctx->pc = 0x1660e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x1660e4: 0xc04a916  jal         func_12A458
    ctx->pc = 0x1660E4u;
    SET_GPR_U32(ctx, 31, 0x1660ECu);
    ctx->pc = 0x1660E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1660E4u;
            // 0x1660e8: 0x8cc60010  lw          $a2, 0x10($a2) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A458u;
    if (runtime->hasFunction(0x12A458u)) {
        auto targetFn = runtime->lookupFunction(0x12A458u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660ECu; }
        if (ctx->pc != 0x1660ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A458_0x12a458(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660ECu; }
        if (ctx->pc != 0x1660ECu) { return; }
    }
    ctx->pc = 0x1660ECu;
label_1660ec:
    // 0x1660ec: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1660ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1660f0: 0xc04cc50  jal         func_133140
    ctx->pc = 0x1660F0u;
    SET_GPR_U32(ctx, 31, 0x1660F8u);
    ctx->pc = 0x1660F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1660F0u;
            // 0x1660f4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133140u;
    if (runtime->hasFunction(0x133140u)) {
        auto targetFn = runtime->lookupFunction(0x133140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660F8u; }
        if (ctx->pc != 0x1660F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133140_0x133140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660F8u; }
        if (ctx->pc != 0x1660F8u) { return; }
    }
    ctx->pc = 0x1660F8u;
label_1660f8:
    // 0x1660f8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1660f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1660fc: 0x3c030016  lui         $v1, 0x16
    ctx->pc = 0x1660fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)22 << 16));
    // 0x166100: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x166100u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x166104: 0x246351c0  addiu       $v1, $v1, 0x51C0
    ctx->pc = 0x166104u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 20928));
    // 0x166108: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x166108u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16610c: 0xae03003c  sw          $v1, 0x3C($s0)
    ctx->pc = 0x16610cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 3));
label_166110:
    // 0x166110: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166110u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_166114:
    // 0x166114: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166114u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166118: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166118u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16611c: 0x3e00008  jr          $ra
    ctx->pc = 0x16611Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16611Cu;
            // 0x166120: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1660B0u: goto label_1660b0;
            case 0x1660ECu: goto label_1660ec;
            case 0x1660F8u: goto label_1660f8;
            case 0x166110u: goto label_166110;
            case 0x166114u: goto label_166114;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166124u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
