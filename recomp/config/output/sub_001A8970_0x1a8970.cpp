#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A8970
// Address: 0x1a8970 - 0x1a8b20
void sub_001A8970_0x1a8970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A8970_0x1a8970");
#endif

    switch (ctx->pc) {
        case 0x1a89d8u: goto label_1a89d8;
        case 0x1a89ecu: goto label_1a89ec;
        case 0x1a8a00u: goto label_1a8a00;
        case 0x1a8a10u: goto label_1a8a10;
        case 0x1a8a2cu: goto label_1a8a2c;
        case 0x1a8a40u: goto label_1a8a40;
        case 0x1a8a50u: goto label_1a8a50;
        case 0x1a8a64u: goto label_1a8a64;
        case 0x1a8a78u: goto label_1a8a78;
        case 0x1a8a8cu: goto label_1a8a8c;
        case 0x1a8a9cu: goto label_1a8a9c;
        case 0x1a8abcu: goto label_1a8abc;
        case 0x1a8ad0u: goto label_1a8ad0;
        case 0x1a8ae0u: goto label_1a8ae0;
        case 0x1a8aecu: goto label_1a8aec;
        case 0x1a8b00u: goto label_1a8b00;
        default: break;
    }

    ctx->pc = 0x1a8970u;

    // 0x1a8970: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a8970u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a8974: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8974u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8978: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a8978u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a897c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a897cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a8980: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a8980u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a8984: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a8984u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8988: 0xa0200fe0  sb          $zero, 0xFE0($at)
    ctx->pc = 0x1a8988u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4064), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a898c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1a898cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8990: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8990u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8994: 0xa0200fd0  sb          $zero, 0xFD0($at)
    ctx->pc = 0x1a8994u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4048), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a8998: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8998u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a899c: 0xa0200ed0  sb          $zero, 0xED0($at)
    ctx->pc = 0x1a899cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 3792), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a89a0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a89a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a89a4: 0xa0201060  sb          $zero, 0x1060($at)
    ctx->pc = 0x1a89a4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4192), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a89a8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a89a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a89ac: 0xa0201160  sb          $zero, 0x1160($at)
    ctx->pc = 0x1a89acu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4448), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a89b0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a89b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a89b4: 0xa0201040  sb          $zero, 0x1040($at)
    ctx->pc = 0x1a89b4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4160), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a89b8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a89b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a89bc: 0xa0201050  sb          $zero, 0x1050($at)
    ctx->pc = 0x1a89bcu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4176), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a89c0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a89c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a89c4: 0x12200022  beqz        $s1, . + 4 + (0x22 << 2)
    ctx->pc = 0x1A89C4u;
    {
        const bool branch_taken_0x1a89c4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A89C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A89C4u;
            // 0x1a89c8: 0xac200ec8  sw          $zero, 0xEC8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 3784), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a89c4) {
            ctx->pc = 0x1A8A50u;
            goto label_1a8a50;
        }
    }
    ctx->pc = 0x1A89CCu;
    // 0x1a89cc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a89ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a89d0: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A89D0u;
    SET_GPR_U32(ctx, 31, 0x1A89D8u);
    ctx->pc = 0x1A89D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A89D0u;
            // 0x1a89d4: 0x24842590  addiu       $a0, $a0, 0x2590 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9616));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A89D8u; }
        if (ctx->pc != 0x1A89D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A89D8u; }
        if (ctx->pc != 0x1A89D8u) { return; }
    }
    ctx->pc = 0x1A89D8u;
label_1a89d8:
    // 0x1a89d8: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a89d8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a89dc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a89dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a89e0: 0x24841000  addiu       $a0, $a0, 0x1000
    ctx->pc = 0x1a89e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4096));
    // 0x1a89e4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1A89E4u;
    SET_GPR_U32(ctx, 31, 0x1A89ECu);
    ctx->pc = 0x1A89E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A89E4u;
            // 0x1a89e8: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A89ECu; }
        if (ctx->pc != 0x1A89ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A89ECu; }
        if (ctx->pc != 0x1A89ECu) { return; }
    }
    ctx->pc = 0x1A89ECu;
label_1a89ec:
    // 0x1a89ec: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a89ecu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a89f0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a89f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a89f4: 0x24841000  addiu       $a0, $a0, 0x1000
    ctx->pc = 0x1a89f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4096));
    // 0x1a89f8: 0xc04c4ce  jal         func_131338
    ctx->pc = 0x1A89F8u;
    SET_GPR_U32(ctx, 31, 0x1A8A00u);
    ctx->pc = 0x1A89FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A89F8u;
            // 0x1a89fc: 0xac311000  sw          $s1, 0x1000($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4096), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131338u;
    if (runtime->hasFunction(0x131338u)) {
        auto targetFn = runtime->lookupFunction(0x131338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A00u; }
        if (ctx->pc != 0x1A8A00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131338_0x131338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A00u; }
        if (ctx->pc != 0x1A8A00u) { return; }
    }
    ctx->pc = 0x1A8A00u;
label_1a8a00:
    // 0x1a8a00: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a8a00u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a8a04: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1a8a04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8a08: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A8A08u;
    SET_GPR_U32(ctx, 31, 0x1A8A10u);
    ctx->pc = 0x1A8A0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8A08u;
            // 0x1a8a0c: 0x24841060  addiu       $a0, $a0, 0x1060 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A10u; }
        if (ctx->pc != 0x1A8A10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A10u; }
        if (ctx->pc != 0x1A8A10u) { return; }
    }
    ctx->pc = 0x1A8A10u;
label_1a8a10:
    // 0x1a8a10: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a8a10u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a8a14: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1a8a14u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1a8a18: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8a18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8a1c: 0x24840fe0  addiu       $a0, $a0, 0xFE0
    ctx->pc = 0x1a8a1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4064));
    // 0x1a8a20: 0x24a525b0  addiu       $a1, $a1, 0x25B0
    ctx->pc = 0x1a8a20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9648));
    // 0x1a8a24: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A8A24u;
    SET_GPR_U32(ctx, 31, 0x1A8A2Cu);
    ctx->pc = 0x1A8A28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8A24u;
            // 0x1a8a28: 0xac200ec8  sw          $zero, 0xEC8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 3784), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A2Cu; }
        if (ctx->pc != 0x1A8A2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A2Cu; }
        if (ctx->pc != 0x1A8A2Cu) { return; }
    }
    ctx->pc = 0x1A8A2Cu;
label_1a8a2c:
    // 0x1a8a2c: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a8a2cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a8a30: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1a8a30u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1a8a34: 0x24840fd0  addiu       $a0, $a0, 0xFD0
    ctx->pc = 0x1a8a34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4048));
    // 0x1a8a38: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A8A38u;
    SET_GPR_U32(ctx, 31, 0x1A8A40u);
    ctx->pc = 0x1A8A3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8A38u;
            // 0x1a8a3c: 0x24a525b0  addiu       $a1, $a1, 0x25B0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9648));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A40u; }
        if (ctx->pc != 0x1A8A40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A40u; }
        if (ctx->pc != 0x1A8A40u) { return; }
    }
    ctx->pc = 0x1A8A40u;
label_1a8a40:
    // 0x1a8a40: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a8a40u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a8a44: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1a8a44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8a48: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A8A48u;
    SET_GPR_U32(ctx, 31, 0x1A8A50u);
    ctx->pc = 0x1A8A4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8A48u;
            // 0x1a8a4c: 0x24840ed0  addiu       $a0, $a0, 0xED0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3792));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A50u; }
        if (ctx->pc != 0x1A8A50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A50u; }
        if (ctx->pc != 0x1A8A50u) { return; }
    }
    ctx->pc = 0x1A8A50u;
label_1a8a50:
    // 0x1a8a50: 0x12000024  beqz        $s0, . + 4 + (0x24 << 2)
    ctx->pc = 0x1A8A50u;
    {
        const bool branch_taken_0x1a8a50 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8A50u;
            // 0x1a8a54: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8a50) {
            ctx->pc = 0x1A8AE4u;
            goto label_1a8ae4;
        }
    }
    ctx->pc = 0x1A8A58u;
    // 0x1a8a58: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a8a58u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a8a5c: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A8A5Cu;
    SET_GPR_U32(ctx, 31, 0x1A8A64u);
    ctx->pc = 0x1A8A60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8A5Cu;
            // 0x1a8a60: 0x248425c0  addiu       $a0, $a0, 0x25C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9664));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A64u; }
        if (ctx->pc != 0x1A8A64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A64u; }
        if (ctx->pc != 0x1A8A64u) { return; }
    }
    ctx->pc = 0x1A8A64u;
label_1a8a64:
    // 0x1a8a64: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a8a64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a8a68: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a8a68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8a6c: 0x24841020  addiu       $a0, $a0, 0x1020
    ctx->pc = 0x1a8a6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4128));
    // 0x1a8a70: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1A8A70u;
    SET_GPR_U32(ctx, 31, 0x1A8A78u);
    ctx->pc = 0x1A8A74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8A70u;
            // 0x1a8a74: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A78u; }
        if (ctx->pc != 0x1A8A78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A78u; }
        if (ctx->pc != 0x1A8A78u) { return; }
    }
    ctx->pc = 0x1A8A78u;
label_1a8a78:
    // 0x1a8a78: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a8a78u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a8a7c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8a7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8a80: 0x24841020  addiu       $a0, $a0, 0x1020
    ctx->pc = 0x1a8a80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4128));
    // 0x1a8a84: 0xc04c422  jal         func_131088
    ctx->pc = 0x1A8A84u;
    SET_GPR_U32(ctx, 31, 0x1A8A8Cu);
    ctx->pc = 0x1A8A88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8A84u;
            // 0x1a8a88: 0xac301020  sw          $s0, 0x1020($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4128), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131088u;
    if (runtime->hasFunction(0x131088u)) {
        auto targetFn = runtime->lookupFunction(0x131088u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A8Cu; }
        if (ctx->pc != 0x1A8A8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131088_0x131088(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A8Cu; }
        if (ctx->pc != 0x1A8A8Cu) { return; }
    }
    ctx->pc = 0x1A8A8Cu;
label_1a8a8c:
    // 0x1a8a8c: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a8a8cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a8a90: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1a8a90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8a94: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A8A94u;
    SET_GPR_U32(ctx, 31, 0x1A8A9Cu);
    ctx->pc = 0x1A8A98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8A94u;
            // 0x1a8a98: 0x24841160  addiu       $a0, $a0, 0x1160 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A9Cu; }
        if (ctx->pc != 0x1A8A9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8A9Cu; }
        if (ctx->pc != 0x1A8A9Cu) { return; }
    }
    ctx->pc = 0x1A8A9Cu;
label_1a8a9c:
    // 0x1a8a9c: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a8a9cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a8aa0: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1a8aa0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1a8aa4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a8aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a8aa8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8aa8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8aac: 0x24840fe0  addiu       $a0, $a0, 0xFE0
    ctx->pc = 0x1a8aacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4064));
    // 0x1a8ab0: 0xac220ec8  sw          $v0, 0xEC8($at)
    ctx->pc = 0x1a8ab0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 3784), GPR_U32(ctx, 2));
    // 0x1a8ab4: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A8AB4u;
    SET_GPR_U32(ctx, 31, 0x1A8ABCu);
    ctx->pc = 0x1A8AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8AB4u;
            // 0x1a8ab8: 0x24a525d8  addiu       $a1, $a1, 0x25D8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9688));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8ABCu; }
        if (ctx->pc != 0x1A8ABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8ABCu; }
        if (ctx->pc != 0x1A8ABCu) { return; }
    }
    ctx->pc = 0x1A8ABCu;
label_1a8abc:
    // 0x1a8abc: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a8abcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a8ac0: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1a8ac0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1a8ac4: 0x24840fd0  addiu       $a0, $a0, 0xFD0
    ctx->pc = 0x1a8ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4048));
    // 0x1a8ac8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A8AC8u;
    SET_GPR_U32(ctx, 31, 0x1A8AD0u);
    ctx->pc = 0x1A8ACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8AC8u;
            // 0x1a8acc: 0x24a525d8  addiu       $a1, $a1, 0x25D8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9688));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8AD0u; }
        if (ctx->pc != 0x1A8AD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8AD0u; }
        if (ctx->pc != 0x1A8AD0u) { return; }
    }
    ctx->pc = 0x1A8AD0u;
label_1a8ad0:
    // 0x1a8ad0: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a8ad0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a8ad4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1a8ad4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8ad8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A8AD8u;
    SET_GPR_U32(ctx, 31, 0x1A8AE0u);
    ctx->pc = 0x1A8ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8AD8u;
            // 0x1a8adc: 0x24840ed0  addiu       $a0, $a0, 0xED0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3792));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8AE0u; }
        if (ctx->pc != 0x1A8AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8AE0u; }
        if (ctx->pc != 0x1A8AE0u) { return; }
    }
    ctx->pc = 0x1A8AE0u;
label_1a8ae0:
    // 0x1a8ae0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1a8ae0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a8ae4:
    // 0x1a8ae4: 0xc04ad8e  jal         func_12B638
    ctx->pc = 0x1A8AE4u;
    SET_GPR_U32(ctx, 31, 0x1A8AECu);
    ctx->pc = 0x12B638u;
    if (runtime->hasFunction(0x12B638u)) {
        auto targetFn = runtime->lookupFunction(0x12B638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8AECu; }
        if (ctx->pc != 0x1A8AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B638_0x12b638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8AECu; }
        if (ctx->pc != 0x1A8AECu) { return; }
    }
    ctx->pc = 0x1A8AECu;
label_1a8aec:
    // 0x1a8aec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a8aecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a8af0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8af0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8af4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1a8af4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a8af8: 0xc04b128  jal         func_12C4A0
    ctx->pc = 0x1A8AF8u;
    SET_GPR_U32(ctx, 31, 0x1A8B00u);
    ctx->pc = 0x1A8AFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8AF8u;
            // 0x1a8afc: 0xac220ec0  sw          $v0, 0xEC0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 3776), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C4A0u;
    if (runtime->hasFunction(0x12C4A0u)) {
        auto targetFn = runtime->lookupFunction(0x12C4A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8B00u; }
        if (ctx->pc != 0x1A8B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C4A0_0x12c4a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8B00u; }
        if (ctx->pc != 0x1A8B00u) { return; }
    }
    ctx->pc = 0x1A8B00u;
label_1a8b00:
    // 0x1a8b00: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a8b00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a8b04: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a8b04u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a8b08: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a8b08u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a8b0c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A8B0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A8B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8B0Cu;
            // 0x1a8b10: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A89D8u: goto label_1a89d8;
            case 0x1A89ECu: goto label_1a89ec;
            case 0x1A8A00u: goto label_1a8a00;
            case 0x1A8A10u: goto label_1a8a10;
            case 0x1A8A2Cu: goto label_1a8a2c;
            case 0x1A8A40u: goto label_1a8a40;
            case 0x1A8A50u: goto label_1a8a50;
            case 0x1A8A64u: goto label_1a8a64;
            case 0x1A8A78u: goto label_1a8a78;
            case 0x1A8A8Cu: goto label_1a8a8c;
            case 0x1A8A9Cu: goto label_1a8a9c;
            case 0x1A8ABCu: goto label_1a8abc;
            case 0x1A8AD0u: goto label_1a8ad0;
            case 0x1A8AE0u: goto label_1a8ae0;
            case 0x1A8AE4u: goto label_1a8ae4;
            case 0x1A8AECu: goto label_1a8aec;
            case 0x1A8B00u: goto label_1a8b00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A8B14u;
    // 0x1a8b14: 0x0  nop
    ctx->pc = 0x1a8b14u;
    // NOP
    // 0x1a8b18: 0x0  nop
    ctx->pc = 0x1a8b18u;
    // NOP
    // 0x1a8b1c: 0x0  nop
    ctx->pc = 0x1a8b1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
