#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001722C0
// Address: 0x1722c0 - 0x172340
void sub_001722C0_0x1722c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001722C0_0x1722c0");
#endif

    switch (ctx->pc) {
        case 0x1722ecu: goto label_1722ec;
        case 0x17231cu: goto label_17231c;
        case 0x172328u: goto label_172328;
        default: break;
    }

    ctx->pc = 0x1722c0u;

    // 0x1722c0: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1722c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1722c4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1722c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1722c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1722C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1722CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1722C8u;
            // 0x1722cc: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1722ECu: goto label_1722ec;
            case 0x172310u: goto label_172310;
            case 0x17231Cu: goto label_17231c;
            case 0x172328u: goto label_172328;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1722D0u;
    // 0x1722d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1722d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1722d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1722d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1722d8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1722d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1722dc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1722dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1722e0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1722e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1722e4: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1722E4u;
    SET_GPR_U32(ctx, 31, 0x1722ECu);
    ctx->pc = 0x1722E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1722E4u;
            // 0x1722e8: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1722ECu; }
        if (ctx->pc != 0x1722ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1722ECu; }
        if (ctx->pc != 0x1722ECu) { return; }
    }
    ctx->pc = 0x1722ECu;
label_1722ec:
    // 0x1722ec: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1722ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1722f0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1722F0u;
    {
        const bool branch_taken_0x1722f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1722F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1722F0u;
            // 0x1722f4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1722f0) {
            ctx->pc = 0x172310u;
            goto label_172310;
        }
    }
    ctx->pc = 0x1722F8u;
    // 0x1722f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1722f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1722fc: 0x34a50144  ori         $a1, $a1, 0x144
    ctx->pc = 0x1722fcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)324);
    // 0x172300: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x172300u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172304: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x172304u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x172308: 0x805a704  j           func_169C10
    ctx->pc = 0x172308u;
    ctx->pc = 0x17230Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172308u;
            // 0x17230c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x172310u;
label_172310:
    // 0x172310: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172310u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172314: 0xc05dd10  jal         func_177440
    ctx->pc = 0x172314u;
    SET_GPR_U32(ctx, 31, 0x17231Cu);
    ctx->pc = 0x172318u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172314u;
            // 0x172318: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177440u;
    if (runtime->hasFunction(0x177440u)) {
        auto targetFn = runtime->lookupFunction(0x177440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17231Cu; }
        if (ctx->pc != 0x17231Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177440_0x177440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17231Cu; }
        if (ctx->pc != 0x17231Cu) { return; }
    }
    ctx->pc = 0x17231Cu;
label_17231c:
    // 0x17231c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17231cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172320: 0xc0598d4  jal         func_166350
    ctx->pc = 0x172320u;
    SET_GPR_U32(ctx, 31, 0x172328u);
    ctx->pc = 0x172324u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172320u;
            // 0x172324: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166350u;
    if (runtime->hasFunction(0x166350u)) {
        auto targetFn = runtime->lookupFunction(0x166350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172328u; }
        if (ctx->pc != 0x172328u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166350_0x166350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172328u; }
        if (ctx->pc != 0x172328u) { return; }
    }
    ctx->pc = 0x172328u;
label_172328:
    // 0x172328: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x172328u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17232c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17232cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172330: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x172330u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172334: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x172334u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x172338: 0x3e00008  jr          $ra
    ctx->pc = 0x172338u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17233Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172338u;
            // 0x17233c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1722ECu: goto label_1722ec;
            case 0x172310u: goto label_172310;
            case 0x17231Cu: goto label_17231c;
            case 0x172328u: goto label_172328;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172340u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
