#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D05B0
// Address: 0x1d05b0 - 0x1d06e0
void sub_001D05B0_0x1d05b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D05B0_0x1d05b0");
#endif

    switch (ctx->pc) {
        case 0x1d061cu: goto label_1d061c;
        case 0x1d0628u: goto label_1d0628;
        case 0x1d0634u: goto label_1d0634;
        case 0x1d0640u: goto label_1d0640;
        case 0x1d064cu: goto label_1d064c;
        case 0x1d0658u: goto label_1d0658;
        case 0x1d0664u: goto label_1d0664;
        case 0x1d0670u: goto label_1d0670;
        case 0x1d06c4u: goto label_1d06c4;
        default: break;
    }

    ctx->pc = 0x1d05b0u;

    // 0x1d05b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d05b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d05b4: 0x30a500ff  andi        $a1, $a1, 0xFF
    ctx->pc = 0x1d05b4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d05b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d05b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d05bc: 0x3c06003f  lui         $a2, 0x3F
    ctx->pc = 0x1d05bcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)63 << 16));
    // 0x1d05c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d05c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d05c4: 0x51880  sll         $v1, $a1, 2
    ctx->pc = 0x1d05c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1d05c8: 0x90870003  lbu         $a3, 0x3($a0)
    ctx->pc = 0x1d05c8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1d05cc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d05ccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d05d0: 0x24c6a380  addiu       $a2, $a2, -0x5C80
    ctx->pc = 0x1d05d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294943616));
    // 0x1d05d4: 0x652021  addu        $a0, $v1, $a1
    ctx->pc = 0x1d05d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1d05d8: 0x3c030038  lui         $v1, 0x38
    ctx->pc = 0x1d05d8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)56 << 16));
    // 0x1d05dc: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1d05dcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d05e0: 0x24636330  addiu       $v1, $v1, 0x6330
    ctx->pc = 0x1d05e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 25392));
    // 0x1d05e4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d05e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d05e8: 0x72180  sll         $a0, $a3, 6
    ctx->pc = 0x1d05e8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 7), 6));
    // 0x1d05ec: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1d05ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1d05f0: 0x420c0  sll         $a0, $a0, 3
    ctx->pc = 0x1d05f0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1d05f4: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1d05f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1d05f8: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1d05f8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d05fc: 0xc42021  addu        $a0, $a2, $a0
    ctx->pc = 0x1d05fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1d0600: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1d0600u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d0604: 0x8c63000c  lw          $v1, 0xC($v1)
    ctx->pc = 0x1d0604u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x1d0608: 0x10600030  beqz        $v1, . + 4 + (0x30 << 2)
    ctx->pc = 0x1D0608u;
    {
        const bool branch_taken_0x1d0608 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0608) {
            ctx->pc = 0x1D06CCu;
            goto label_1d06cc;
        }
    }
    ctx->pc = 0x1D0610u;
    // 0x1d0610: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d0610u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d0614: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0614u;
    SET_GPR_U32(ctx, 31, 0x1D061Cu);
    ctx->pc = 0x1D0618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0614u;
            // 0x1d0618: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D061Cu; }
        if (ctx->pc != 0x1D061Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D061Cu; }
        if (ctx->pc != 0x1D061Cu) { return; }
    }
    ctx->pc = 0x1D061Cu;
label_1d061c:
    // 0x1d061c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d061cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0620: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0620u;
    SET_GPR_U32(ctx, 31, 0x1D0628u);
    ctx->pc = 0x1D0624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0620u;
            // 0x1d0624: 0x24050800  addiu       $a1, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0628u; }
        if (ctx->pc != 0x1D0628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0628u; }
        if (ctx->pc != 0x1D0628u) { return; }
    }
    ctx->pc = 0x1D0628u;
label_1d0628:
    // 0x1d0628: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d0628u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d062c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D062Cu;
    SET_GPR_U32(ctx, 31, 0x1D0634u);
    ctx->pc = 0x1D0630u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D062Cu;
            // 0x1d0630: 0x34058000  ori         $a1, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0634u; }
        if (ctx->pc != 0x1D0634u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0634u; }
        if (ctx->pc != 0x1D0634u) { return; }
    }
    ctx->pc = 0x1D0634u;
label_1d0634:
    // 0x1d0634: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d0634u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d0638: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0638u;
    SET_GPR_U32(ctx, 31, 0x1D0640u);
    ctx->pc = 0x1D063Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0638u;
            // 0x1d063c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0640u; }
        if (ctx->pc != 0x1D0640u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0640u; }
        if (ctx->pc != 0x1D0640u) { return; }
    }
    ctx->pc = 0x1D0640u;
label_1d0640:
    // 0x1d0640: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d0640u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d0644: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0644u;
    SET_GPR_U32(ctx, 31, 0x1D064Cu);
    ctx->pc = 0x1D0648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0644u;
            // 0x1d0648: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D064Cu; }
        if (ctx->pc != 0x1D064Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D064Cu; }
        if (ctx->pc != 0x1D064Cu) { return; }
    }
    ctx->pc = 0x1D064Cu;
label_1d064c:
    // 0x1d064c: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d064cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d0650: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0650u;
    SET_GPR_U32(ctx, 31, 0x1D0658u);
    ctx->pc = 0x1D0654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0650u;
            // 0x1d0654: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0658u; }
        if (ctx->pc != 0x1D0658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0658u; }
        if (ctx->pc != 0x1D0658u) { return; }
    }
    ctx->pc = 0x1D0658u;
label_1d0658:
    // 0x1d0658: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d0658u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d065c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D065Cu;
    SET_GPR_U32(ctx, 31, 0x1D0664u);
    ctx->pc = 0x1D0660u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D065Cu;
            // 0x1d0660: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0664u; }
        if (ctx->pc != 0x1D0664u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0664u; }
        if (ctx->pc != 0x1D0664u) { return; }
    }
    ctx->pc = 0x1D0664u;
label_1d0664:
    // 0x1d0664: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d0664u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0668: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0668u;
    SET_GPR_U32(ctx, 31, 0x1D0670u);
    ctx->pc = 0x1D066Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0668u;
            // 0x1d066c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0670u; }
        if (ctx->pc != 0x1D0670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0670u; }
        if (ctx->pc != 0x1D0670u) { return; }
    }
    ctx->pc = 0x1D0670u;
label_1d0670:
    // 0x1d0670: 0x92030003  lbu         $v1, 0x3($s0)
    ctx->pc = 0x1d0670u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1d0674: 0x3c06003f  lui         $a2, 0x3F
    ctx->pc = 0x1d0674u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)63 << 16));
    // 0x1d0678: 0x24c6a380  addiu       $a2, $a2, -0x5C80
    ctx->pc = 0x1d0678u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294943616));
    // 0x1d067c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1d067cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0680: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x1d0680u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d0684: 0x31180  sll         $v0, $v1, 6
    ctx->pc = 0x1d0684u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 6));
    // 0x1d0688: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d0688u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d068c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d068cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d0690: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d0690u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d0694: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1d0694u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1d0698: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1d0698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1d069c: 0xa0450000  sb          $a1, 0x0($v0)
    ctx->pc = 0x1d069cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1d06a0: 0x92030003  lbu         $v1, 0x3($s0)
    ctx->pc = 0x1d06a0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1d06a4: 0x31180  sll         $v0, $v1, 6
    ctx->pc = 0x1d06a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 6));
    // 0x1d06a8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d06a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d06ac: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d06acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d06b0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d06b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d06b4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1d06b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1d06b8: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1d06b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1d06bc: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D06BCu;
    SET_GPR_U32(ctx, 31, 0x1D06C4u);
    ctx->pc = 0x1D06C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D06BCu;
            // 0x1d06c0: 0x24500004  addiu       $s0, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D06C4u; }
        if (ctx->pc != 0x1D06C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D06C4u; }
        if (ctx->pc != 0x1D06C4u) { return; }
    }
    ctx->pc = 0x1D06C4u;
label_1d06c4:
    // 0x1d06c4: 0xae020808  sw          $v0, 0x808($s0)
    ctx->pc = 0x1d06c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2056), GPR_U32(ctx, 2));
    // 0x1d06c8: 0xae000818  sw          $zero, 0x818($s0)
    ctx->pc = 0x1d06c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2072), GPR_U32(ctx, 0));
label_1d06cc:
    // 0x1d06cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d06ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d06d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d06d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d06d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D06D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D06D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D06D4u;
            // 0x1d06d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D061Cu: goto label_1d061c;
            case 0x1D0628u: goto label_1d0628;
            case 0x1D0634u: goto label_1d0634;
            case 0x1D0640u: goto label_1d0640;
            case 0x1D064Cu: goto label_1d064c;
            case 0x1D0658u: goto label_1d0658;
            case 0x1D0664u: goto label_1d0664;
            case 0x1D0670u: goto label_1d0670;
            case 0x1D06C4u: goto label_1d06c4;
            case 0x1D06CCu: goto label_1d06cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D06DCu;
    // 0x1d06dc: 0x0  nop
    ctx->pc = 0x1d06dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
