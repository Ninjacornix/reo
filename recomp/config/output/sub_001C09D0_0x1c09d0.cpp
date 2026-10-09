#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C09D0
// Address: 0x1c09d0 - 0x1c0dc0
void sub_001C09D0_0x1c09d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C09D0_0x1c09d0");
#endif

    switch (ctx->pc) {
        case 0x1c0a54u: goto label_1c0a54;
        case 0x1c0adcu: goto label_1c0adc;
        case 0x1c0b38u: goto label_1c0b38;
        case 0x1c0b4cu: goto label_1c0b4c;
        case 0x1c0b60u: goto label_1c0b60;
        case 0x1c0ba0u: goto label_1c0ba0;
        case 0x1c0bdcu: goto label_1c0bdc;
        case 0x1c0c20u: goto label_1c0c20;
        case 0x1c0cc0u: goto label_1c0cc0;
        case 0x1c0d04u: goto label_1c0d04;
        case 0x1c0d48u: goto label_1c0d48;
        case 0x1c0da8u: goto label_1c0da8;
        default: break;
    }

    ctx->pc = 0x1c09d0u;

    // 0x1c09d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c09d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c09d4: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x1c09d4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x1c09d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c09d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c09dc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c09dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c09e0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c09e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c09e4: 0x24c65160  addiu       $a2, $a2, 0x5160
    ctx->pc = 0x1c09e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 20832));
    // 0x1c09e8: 0x8c276cf0  lw          $a3, 0x6CF0($at)
    ctx->pc = 0x1c09e8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27888)));
    // 0x1c09ec: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c09ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c09f0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c09f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c09f4: 0x73880  sll         $a3, $a3, 2
    ctx->pc = 0x1c09f4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1c09f8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c09f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c09fc: 0xc73021  addu        $a2, $a2, $a3
    ctx->pc = 0x1c09fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1c0a00: 0x8cd00000  lw          $s0, 0x0($a2)
    ctx->pc = 0x1c0a00u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1c0a04: 0xac236ce8  sw          $v1, 0x6CE8($at)
    ctx->pc = 0x1c0a04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27880), GPR_U32(ctx, 3));
    // 0x1c0a08: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0a08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0a0c: 0xac226c74  sw          $v0, 0x6C74($at)
    ctx->pc = 0x1c0a0cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27764), GPR_U32(ctx, 2));
    // 0x1c0a10: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0a10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0a14: 0xac206c50  sw          $zero, 0x6C50($at)
    ctx->pc = 0x1c0a14u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27728), GPR_U32(ctx, 0));
    // 0x1c0a18: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0a18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0a1c: 0xac206c54  sw          $zero, 0x6C54($at)
    ctx->pc = 0x1c0a1cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27732), GPR_U32(ctx, 0));
    // 0x1c0a20: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0a20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0a24: 0xac206c58  sw          $zero, 0x6C58($at)
    ctx->pc = 0x1c0a24u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27736), GPR_U32(ctx, 0));
    // 0x1c0a28: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0a28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0a2c: 0xac246c64  sw          $a0, 0x6C64($at)
    ctx->pc = 0x1c0a2cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27748), GPR_U32(ctx, 4));
    // 0x1c0a30: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0a30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0a34: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1c0a34u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1c0a38: 0xac256cec  sw          $a1, 0x6CEC($at)
    ctx->pc = 0x1c0a38u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27884), GPR_U32(ctx, 5));
    // 0x1c0a3c: 0x24846c94  addiu       $a0, $a0, 0x6C94
    ctx->pc = 0x1c0a3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27796));
    // 0x1c0a40: 0x8e060010  lw          $a2, 0x10($s0)
    ctx->pc = 0x1c0a40u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c0a44: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c0a44u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c0a48: 0x24a50640  addiu       $a1, $a1, 0x640
    ctx->pc = 0x1c0a48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1600));
    // 0x1c0a4c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C0A4Cu;
    SET_GPR_U32(ctx, 31, 0x1C0A54u);
    ctx->pc = 0x1C0A50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0A4Cu;
            // 0x1c0a50: 0xc0382d  daddu       $a3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0A54u; }
        if (ctx->pc != 0x1C0A54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0A54u; }
        if (ctx->pc != 0x1C0A54u) { return; }
    }
    ctx->pc = 0x1C0A54u;
label_1c0a54:
    // 0x1c0a54: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x1c0a54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1c0a58: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0a58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0a5c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0a5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0a60: 0xac246cd8  sw          $a0, 0x6CD8($at)
    ctx->pc = 0x1c0a60u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27864), GPR_U32(ctx, 4));
    // 0x1c0a64: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0a64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0a68: 0xac236cf8  sw          $v1, 0x6CF8($at)
    ctx->pc = 0x1c0a68u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27896), GPR_U32(ctx, 3));
    // 0x1c0a6c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c0a6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c0a70: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c0a70u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c0a74: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0A74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0A74u;
            // 0x1c0a78: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0A54u: goto label_1c0a54;
            case 0x1C0AD4u: goto label_1c0ad4;
            case 0x1C0ADCu: goto label_1c0adc;
            case 0x1C0B0Cu: goto label_1c0b0c;
            case 0x1C0B18u: goto label_1c0b18;
            case 0x1C0B24u: goto label_1c0b24;
            case 0x1C0B38u: goto label_1c0b38;
            case 0x1C0B4Cu: goto label_1c0b4c;
            case 0x1C0B58u: goto label_1c0b58;
            case 0x1C0B60u: goto label_1c0b60;
            case 0x1C0B7Cu: goto label_1c0b7c;
            case 0x1C0B90u: goto label_1c0b90;
            case 0x1C0BA0u: goto label_1c0ba0;
            case 0x1C0BDCu: goto label_1c0bdc;
            case 0x1C0BF8u: goto label_1c0bf8;
            case 0x1C0C18u: goto label_1c0c18;
            case 0x1C0C20u: goto label_1c0c20;
            case 0x1C0C4Cu: goto label_1c0c4c;
            case 0x1C0C6Cu: goto label_1c0c6c;
            case 0x1C0C88u: goto label_1c0c88;
            case 0x1C0C98u: goto label_1c0c98;
            case 0x1C0CA8u: goto label_1c0ca8;
            case 0x1C0CB8u: goto label_1c0cb8;
            case 0x1C0CC0u: goto label_1c0cc0;
            case 0x1C0CDCu: goto label_1c0cdc;
            case 0x1C0CECu: goto label_1c0cec;
            case 0x1C0CFCu: goto label_1c0cfc;
            case 0x1C0D04u: goto label_1c0d04;
            case 0x1C0D20u: goto label_1c0d20;
            case 0x1C0D30u: goto label_1c0d30;
            case 0x1C0D40u: goto label_1c0d40;
            case 0x1C0D48u: goto label_1c0d48;
            case 0x1C0D64u: goto label_1c0d64;
            case 0x1C0D84u: goto label_1c0d84;
            case 0x1C0D90u: goto label_1c0d90;
            case 0x1C0D9Cu: goto label_1c0d9c;
            case 0x1C0DA0u: goto label_1c0da0;
            case 0x1C0DA8u: goto label_1c0da8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C0A7Cu;
    // 0x1c0a7c: 0x0  nop
    ctx->pc = 0x1c0a7cu;
    // NOP
    // 0x1c0a80: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c0a80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c0a84: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1c0a84u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1c0a88: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c0a88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c0a8c: 0x24635160  addiu       $v1, $v1, 0x5160
    ctx->pc = 0x1c0a8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 20832));
    // 0x1c0a90: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c0a90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c0a94: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c0a94u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c0a98: 0x8c8500a0  lw          $a1, 0xA0($a0)
    ctx->pc = 0x1c0a98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 160)));
    // 0x1c0a9c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1c0a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c0aa0: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1c0aa0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1c0aa4: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1c0aa4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1c0aa8: 0x2c410007  sltiu       $at, $v0, 0x7
    ctx->pc = 0x1c0aa8u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)7) ? 1 : 0);
    // 0x1c0aac: 0x8c700000  lw          $s0, 0x0($v1)
    ctx->pc = 0x1c0aacu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1c0ab0: 0x102000ba  beqz        $at, . + 4 + (0xBA << 2)
    ctx->pc = 0x1C0AB0u;
    {
        const bool branch_taken_0x1c0ab0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0AB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0AB0u;
            // 0x1c0ab4: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0ab0) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0AB8u;
    // 0x1c0ab8: 0x3c030025  lui         $v1, 0x25
    ctx->pc = 0x1c0ab8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)37 << 16));
    // 0x1c0abc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1c0abcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1c0ac0: 0x24630650  addiu       $v1, $v1, 0x650
    ctx->pc = 0x1c0ac0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1616));
    // 0x1c0ac4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c0ac4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c0ac8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c0ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c0acc: 0x400008  jr          $v0
    ctx->pc = 0x1C0ACCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0AD4u: goto label_1c0ad4;
            case 0x1C0B58u: goto label_1c0b58;
            case 0x1C0BA0u: goto label_1c0ba0;
            case 0x1C0C18u: goto label_1c0c18;
            case 0x1C0CB8u: goto label_1c0cb8;
            case 0x1C0CFCu: goto label_1c0cfc;
            case 0x1C0D40u: goto label_1c0d40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C0AD4u;
label_1c0ad4:
    // 0x1c0ad4: 0xc06fe10  jal         func_1BF840
    ctx->pc = 0x1C0AD4u;
    SET_GPR_U32(ctx, 31, 0x1C0ADCu);
    ctx->pc = 0x1BF840u;
    if (runtime->hasFunction(0x1BF840u)) {
        auto targetFn = runtime->lookupFunction(0x1BF840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0ADCu; }
        if (ctx->pc != 0x1C0ADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF840_0x1bf840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0ADCu; }
        if (ctx->pc != 0x1C0ADCu) { return; }
    }
    ctx->pc = 0x1C0ADCu;
label_1c0adc:
    // 0x1c0adc: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c0adcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c0ae0: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C0AE0u;
    {
        const bool branch_taken_0x1c0ae0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C0AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0AE0u;
            // 0x1c0ae4: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0ae0) {
            ctx->pc = 0x1C0B24u;
            goto label_1c0b24;
        }
    }
    ctx->pc = 0x1C0AE8u;
    // 0x1c0ae8: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C0AE8u;
    {
        const bool branch_taken_0x1c0ae8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0ae8) {
            ctx->pc = 0x1C0B24u;
            goto label_1c0b24;
        }
    }
    ctx->pc = 0x1C0AF0u;
    // 0x1c0af0: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c0af0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c0af4: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C0AF4u;
    {
        const bool branch_taken_0x1c0af4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0af4) {
            ctx->pc = 0x1C0B18u;
            goto label_1c0b18;
        }
    }
    ctx->pc = 0x1C0AFCu;
    // 0x1c0afc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0AFCu;
    {
        const bool branch_taken_0x1c0afc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0afc) {
            ctx->pc = 0x1C0B0Cu;
            goto label_1c0b0c;
        }
    }
    ctx->pc = 0x1C0B04u;
    // 0x1c0b04: 0x100000a6  b           . + 4 + (0xA6 << 2)
    ctx->pc = 0x1C0B04u;
    {
        const bool branch_taken_0x1c0b04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0B04u;
            // 0x1c0b08: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0b04) {
            ctx->pc = 0x1C0DA0u;
            goto label_1c0da0;
        }
    }
    ctx->pc = 0x1C0B0Cu;
label_1c0b0c:
    // 0x1c0b0c: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c0b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c0b10: 0x100000a2  b           . + 4 + (0xA2 << 2)
    ctx->pc = 0x1C0B10u;
    {
        const bool branch_taken_0x1c0b10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0B14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0B10u;
            // 0x1c0b14: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0b10) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0B18u;
label_1c0b18:
    // 0x1c0b18: 0x2402ff02  addiu       $v0, $zero, -0xFE
    ctx->pc = 0x1c0b18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
    // 0x1c0b1c: 0x1000009f  b           . + 4 + (0x9F << 2)
    ctx->pc = 0x1C0B1Cu;
    {
        const bool branch_taken_0x1c0b1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0B1Cu;
            // 0x1c0b20: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0b1c) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0B24u;
label_1c0b24:
    // 0x1c0b24: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1c0b24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c0b28: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c0b28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c0b2c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0b30: 0xc0704f0  jal         func_1C13C0
    ctx->pc = 0x1C0B30u;
    SET_GPR_U32(ctx, 31, 0x1C0B38u);
    ctx->pc = 0x1C0B34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0B30u;
            // 0x1c0b34: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C13C0u;
    if (runtime->hasFunction(0x1C13C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C13C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0B38u; }
        if (ctx->pc != 0x1C0B38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C13C0_0x1c13c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0B38u; }
        if (ctx->pc != 0x1C0B38u) { return; }
    }
    ctx->pc = 0x1C0B38u;
label_1c0b38:
    // 0x1c0b38: 0x8e060010  lw          $a2, 0x10($s0)
    ctx->pc = 0x1c0b38u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c0b3c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c0b3cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c0b40: 0x26240044  addiu       $a0, $s1, 0x44
    ctx->pc = 0x1c0b40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 68));
    // 0x1c0b44: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C0B44u;
    SET_GPR_U32(ctx, 31, 0x1C0B4Cu);
    ctx->pc = 0x1C0B48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0B44u;
            // 0x1c0b48: 0x24a50648  addiu       $a1, $a1, 0x648 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1608));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0B4Cu; }
        if (ctx->pc != 0x1C0B4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0B4Cu; }
        if (ctx->pc != 0x1C0B4Cu) { return; }
    }
    ctx->pc = 0x1C0B4Cu;
label_1c0b4c:
    // 0x1c0b4c: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1c0b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1c0b50: 0x10000092  b           . + 4 + (0x92 << 2)
    ctx->pc = 0x1C0B50u;
    {
        const bool branch_taken_0x1c0b50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0B50u;
            // 0x1c0b54: 0xae220094  sw          $v0, 0x94($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 148), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0b50) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0B58u;
label_1c0b58:
    // 0x1c0b58: 0xc06ff00  jal         func_1BFC00
    ctx->pc = 0x1C0B58u;
    SET_GPR_U32(ctx, 31, 0x1C0B60u);
    ctx->pc = 0x1BFC00u;
    if (runtime->hasFunction(0x1BFC00u)) {
        auto targetFn = runtime->lookupFunction(0x1BFC00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0B60u; }
        if (ctx->pc != 0x1C0B60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFC00_0x1bfc00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0B60u; }
        if (ctx->pc != 0x1C0B60u) { return; }
    }
    ctx->pc = 0x1C0B60u;
label_1c0b60:
    // 0x1c0b60: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0b60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0b64: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1C0B64u;
    {
        const bool branch_taken_0x1c0b64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0b64) {
            ctx->pc = 0x1C0B90u;
            goto label_1c0b90;
        }
    }
    ctx->pc = 0x1C0B6Cu;
    // 0x1c0b6c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0B6Cu;
    {
        const bool branch_taken_0x1c0b6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0b6c) {
            ctx->pc = 0x1C0B7Cu;
            goto label_1c0b7c;
        }
    }
    ctx->pc = 0x1C0B74u;
    // 0x1c0b74: 0x10000089  b           . + 4 + (0x89 << 2)
    ctx->pc = 0x1C0B74u;
    {
        const bool branch_taken_0x1c0b74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0b74) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0B7Cu;
label_1c0b7c:
    // 0x1c0b7c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1c0b7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c0b80: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0b80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0b84: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1c0b84u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1c0b88: 0x10000084  b           . + 4 + (0x84 << 2)
    ctx->pc = 0x1C0B88u;
    {
        const bool branch_taken_0x1c0b88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0B8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0B88u;
            // 0x1c0b8c: 0xae200008  sw          $zero, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0b88) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0B90u;
label_1c0b90:
    // 0x1c0b90: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c0b90u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c0b94: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0b94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0b98: 0x10000080  b           . + 4 + (0x80 << 2)
    ctx->pc = 0x1C0B98u;
    {
        const bool branch_taken_0x1c0b98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0B98u;
            // 0x1c0b9c: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0b98) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0BA0u;
label_1c0ba0:
    // 0x1c0ba0: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x1c0ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1c0ba4: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1c0ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1c0ba8: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1c0ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1c0bac: 0x8c42000c  lw          $v0, 0xC($v0)
    ctx->pc = 0x1c0bacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1c0bb0: 0x1040006c  beqz        $v0, . + 4 + (0x6C << 2)
    ctx->pc = 0x1C0BB0u;
    {
        const bool branch_taken_0x1c0bb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0BB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0BB0u;
            // 0x1c0bb4: 0xae220084  sw          $v0, 0x84($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 132), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0bb0) {
            ctx->pc = 0x1C0D64u;
            goto label_1c0d64;
        }
    }
    ctx->pc = 0x1C0BB8u;
    // 0x1c0bb8: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x1c0bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1c0bbc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c0bbcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c0bc0: 0x8e060010  lw          $a2, 0x10($s0)
    ctx->pc = 0x1c0bc0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c0bc4: 0x26240044  addiu       $a0, $s1, 0x44
    ctx->pc = 0x1c0bc4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 68));
    // 0x1c0bc8: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1c0bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1c0bcc: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1c0bccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1c0bd0: 0x8c470010  lw          $a3, 0x10($v0)
    ctx->pc = 0x1c0bd0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1c0bd4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C0BD4u;
    SET_GPR_U32(ctx, 31, 0x1C0BDCu);
    ctx->pc = 0x1C0BD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0BD4u;
            // 0x1c0bd8: 0x24a50640  addiu       $a1, $a1, 0x640 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1600));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0BDCu; }
        if (ctx->pc != 0x1C0BDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0BDCu; }
        if (ctx->pc != 0x1C0BDCu) { return; }
    }
    ctx->pc = 0x1C0BDCu;
label_1c0bdc:
    // 0x1c0bdc: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x1c0bdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1c0be0: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C0BE0u;
    {
        const bool branch_taken_0x1c0be0 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1c0be0) {
            ctx->pc = 0x1C0BF8u;
            goto label_1c0bf8;
        }
    }
    ctx->pc = 0x1C0BE8u;
    // 0x1c0be8: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1c0be8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1c0bec: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1c0becu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1c0bf0: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1c0bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1c0bf4: 0xae22009c  sw          $v0, 0x9C($s1)
    ctx->pc = 0x1c0bf4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 156), GPR_U32(ctx, 2));
label_1c0bf8:
    // 0x1c0bf8: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x1c0bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1c0bfc: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1c0bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1c0c00: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1c0c00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1c0c04: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1c0c04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1c0c08: 0xae220088  sw          $v0, 0x88($s1)
    ctx->pc = 0x1c0c08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 136), GPR_U32(ctx, 2));
    // 0x1c0c0c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1c0c0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c0c10: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0c10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0c14: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1c0c14u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
label_1c0c18:
    // 0x1c0c18: 0xc06fe94  jal         func_1BFA50
    ctx->pc = 0x1C0C18u;
    SET_GPR_U32(ctx, 31, 0x1C0C20u);
    ctx->pc = 0x1C0C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0C18u;
            // 0x1c0c1c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BFA50u;
    if (runtime->hasFunction(0x1BFA50u)) {
        auto targetFn = runtime->lookupFunction(0x1BFA50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0C20u; }
        if (ctx->pc != 0x1C0C20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFA50_0x1bfa50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0C20u; }
        if (ctx->pc != 0x1C0C20u) { return; }
    }
    ctx->pc = 0x1C0C20u;
label_1c0c20:
    // 0x1c0c20: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c0c20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c0c24: 0x10430020  beq         $v0, $v1, . + 4 + (0x20 << 2)
    ctx->pc = 0x1C0C24u;
    {
        const bool branch_taken_0x1c0c24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C0C28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0C24u;
            // 0x1c0c28: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0c24) {
            ctx->pc = 0x1C0CA8u;
            goto label_1c0ca8;
        }
    }
    ctx->pc = 0x1C0C2Cu;
    // 0x1c0c2c: 0x1043001a  beq         $v0, $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1C0C2Cu;
    {
        const bool branch_taken_0x1c0c2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C0C30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0C2Cu;
            // 0x1c0c30: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0c2c) {
            ctx->pc = 0x1C0C98u;
            goto label_1c0c98;
        }
    }
    ctx->pc = 0x1C0C34u;
    // 0x1c0c34: 0x10440014  beq         $v0, $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1C0C34u;
    {
        const bool branch_taken_0x1c0c34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x1c0c34) {
            ctx->pc = 0x1C0C88u;
            goto label_1c0c88;
        }
    }
    ctx->pc = 0x1C0C3Cu;
    // 0x1c0c3c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0C3Cu;
    {
        const bool branch_taken_0x1c0c3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0C3Cu;
            // 0x1c0c40: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0c3c) {
            ctx->pc = 0x1C0C4Cu;
            goto label_1c0c4c;
        }
    }
    ctx->pc = 0x1C0C44u;
    // 0x1c0c44: 0x10000055  b           . + 4 + (0x55 << 2)
    ctx->pc = 0x1C0C44u;
    {
        const bool branch_taken_0x1c0c44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0c44) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0C4Cu;
label_1c0c4c:
    // 0x1c0c4c: 0x8e220088  lw          $v0, 0x88($s1)
    ctx->pc = 0x1c0c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 136)));
    // 0x1c0c50: 0x8c236ac0  lw          $v1, 0x6AC0($at)
    ctx->pc = 0x1c0c50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27328)));
    // 0x1c0c54: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C0C54u;
    {
        const bool branch_taken_0x1c0c54 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c0c54) {
            ctx->pc = 0x1C0C6Cu;
            goto label_1c0c6c;
        }
    }
    ctx->pc = 0x1C0C5Cu;
    // 0x1c0c5c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1c0c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c0c60: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0c60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0c64: 0x1000004d  b           . + 4 + (0x4D << 2)
    ctx->pc = 0x1C0C64u;
    {
        const bool branch_taken_0x1c0c64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0C68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0C64u;
            // 0x1c0c68: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0c64) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0C6Cu;
label_1c0c6c:
    // 0x1c0c6c: 0x8e220084  lw          $v0, 0x84($s1)
    ctx->pc = 0x1c0c6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 132)));
    // 0x1c0c70: 0x1044003c  beq         $v0, $a0, . + 4 + (0x3C << 2)
    ctx->pc = 0x1C0C70u;
    {
        const bool branch_taken_0x1c0c70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x1c0c70) {
            ctx->pc = 0x1C0D64u;
            goto label_1c0d64;
        }
    }
    ctx->pc = 0x1C0C78u;
    // 0x1c0c78: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1c0c78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c0c7c: 0x24420003  addiu       $v0, $v0, 0x3
    ctx->pc = 0x1c0c7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 3));
    // 0x1c0c80: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1C0C80u;
    {
        const bool branch_taken_0x1c0c80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0C84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0C80u;
            // 0x1c0c84: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0c80) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0C88u;
label_1c0c88:
    // 0x1c0c88: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1c0c88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c0c8c: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1c0c8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1c0c90: 0x10000042  b           . + 4 + (0x42 << 2)
    ctx->pc = 0x1C0C90u;
    {
        const bool branch_taken_0x1c0c90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0C90u;
            // 0x1c0c94: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0c90) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0C98u;
label_1c0c98:
    // 0x1c0c98: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c0c98u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c0c9c: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c0c9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c0ca0: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x1C0CA0u;
    {
        const bool branch_taken_0x1c0ca0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0CA0u;
            // 0x1c0ca4: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0ca0) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0CA8u;
label_1c0ca8:
    // 0x1c0ca8: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c0ca8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c0cac: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0cacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0cb0: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1C0CB0u;
    {
        const bool branch_taken_0x1c0cb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0CB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0CB0u;
            // 0x1c0cb4: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0cb0) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0CB8u;
label_1c0cb8:
    // 0x1c0cb8: 0xc06ffb0  jal         func_1BFEC0
    ctx->pc = 0x1C0CB8u;
    SET_GPR_U32(ctx, 31, 0x1C0CC0u);
    ctx->pc = 0x1BFEC0u;
    if (runtime->hasFunction(0x1BFEC0u)) {
        auto targetFn = runtime->lookupFunction(0x1BFEC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0CC0u; }
        if (ctx->pc != 0x1C0CC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFEC0_0x1bfec0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0CC0u; }
        if (ctx->pc != 0x1C0CC0u) { return; }
    }
    ctx->pc = 0x1C0CC0u;
label_1c0cc0:
    // 0x1c0cc0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0cc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0cc4: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C0CC4u;
    {
        const bool branch_taken_0x1c0cc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0cc4) {
            ctx->pc = 0x1C0CECu;
            goto label_1c0cec;
        }
    }
    ctx->pc = 0x1C0CCCu;
    // 0x1c0ccc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0CCCu;
    {
        const bool branch_taken_0x1c0ccc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0ccc) {
            ctx->pc = 0x1C0CDCu;
            goto label_1c0cdc;
        }
    }
    ctx->pc = 0x1C0CD4u;
    // 0x1c0cd4: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1C0CD4u;
    {
        const bool branch_taken_0x1c0cd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0cd4) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0CDCu;
label_1c0cdc:
    // 0x1c0cdc: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1c0cdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c0ce0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0ce4: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1C0CE4u;
    {
        const bool branch_taken_0x1c0ce4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0CE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0CE4u;
            // 0x1c0ce8: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0ce4) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0CECu;
label_1c0cec:
    // 0x1c0cec: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c0cecu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c0cf0: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0cf4: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1C0CF4u;
    {
        const bool branch_taken_0x1c0cf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0CF4u;
            // 0x1c0cf8: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0cf4) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0CFCu;
label_1c0cfc:
    // 0x1c0cfc: 0xc06ff54  jal         func_1BFD50
    ctx->pc = 0x1C0CFCu;
    SET_GPR_U32(ctx, 31, 0x1C0D04u);
    ctx->pc = 0x1BFD50u;
    if (runtime->hasFunction(0x1BFD50u)) {
        auto targetFn = runtime->lookupFunction(0x1BFD50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0D04u; }
        if (ctx->pc != 0x1C0D04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFD50_0x1bfd50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0D04u; }
        if (ctx->pc != 0x1C0D04u) { return; }
    }
    ctx->pc = 0x1C0D04u;
label_1c0d04:
    // 0x1c0d04: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0d04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0d08: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C0D08u;
    {
        const bool branch_taken_0x1c0d08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0d08) {
            ctx->pc = 0x1C0D30u;
            goto label_1c0d30;
        }
    }
    ctx->pc = 0x1C0D10u;
    // 0x1c0d10: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0D10u;
    {
        const bool branch_taken_0x1c0d10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0d10) {
            ctx->pc = 0x1C0D20u;
            goto label_1c0d20;
        }
    }
    ctx->pc = 0x1C0D18u;
    // 0x1c0d18: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1C0D18u;
    {
        const bool branch_taken_0x1c0d18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0d18) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0D20u;
label_1c0d20:
    // 0x1c0d20: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1c0d20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c0d24: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0d24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0d28: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1C0D28u;
    {
        const bool branch_taken_0x1c0d28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0D2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0D28u;
            // 0x1c0d2c: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0d28) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0D30u;
label_1c0d30:
    // 0x1c0d30: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c0d30u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c0d34: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0d34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0d38: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1C0D38u;
    {
        const bool branch_taken_0x1c0d38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0D38u;
            // 0x1c0d3c: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0d38) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0D40u;
label_1c0d40:
    // 0x1c0d40: 0xc06ff80  jal         func_1BFE00
    ctx->pc = 0x1C0D40u;
    SET_GPR_U32(ctx, 31, 0x1C0D48u);
    ctx->pc = 0x1BFE00u;
    if (runtime->hasFunction(0x1BFE00u)) {
        auto targetFn = runtime->lookupFunction(0x1BFE00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0D48u; }
        if (ctx->pc != 0x1C0D48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFE00_0x1bfe00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0D48u; }
        if (ctx->pc != 0x1C0D48u) { return; }
    }
    ctx->pc = 0x1C0D48u;
label_1c0d48:
    // 0x1c0d48: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0d48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0d4c: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C0D4Cu;
    {
        const bool branch_taken_0x1c0d4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0d4c) {
            ctx->pc = 0x1C0D90u;
            goto label_1c0d90;
        }
    }
    ctx->pc = 0x1C0D54u;
    // 0x1c0d54: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0D54u;
    {
        const bool branch_taken_0x1c0d54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0d54) {
            ctx->pc = 0x1C0D64u;
            goto label_1c0d64;
        }
    }
    ctx->pc = 0x1C0D5Cu;
    // 0x1c0d5c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C0D5Cu;
    {
        const bool branch_taken_0x1c0d5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0d5c) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0D64u;
label_1c0d64:
    // 0x1c0d64: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x1c0d64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1c0d68: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0d68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0d6c: 0x28410005  slti        $at, $v0, 0x5
    ctx->pc = 0x1c0d6cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x1c0d70: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C0D70u;
    {
        const bool branch_taken_0x1c0d70 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0D70u;
            // 0x1c0d74: 0xae220008  sw          $v0, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0d70) {
            ctx->pc = 0x1C0D84u;
            goto label_1c0d84;
        }
    }
    ctx->pc = 0x1C0D78u;
    // 0x1c0d78: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c0d78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c0d7c: 0x1000ff88  b           . + 4 + (-0x78 << 2)
    ctx->pc = 0x1C0D7Cu;
    {
        const bool branch_taken_0x1c0d7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0D7Cu;
            // 0x1c0d80: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0d7c) {
            ctx->pc = 0x1C0BA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c0ba0;
        }
    }
    ctx->pc = 0x1C0D84u;
label_1c0d84:
    // 0x1c0d84: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c0d84u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c0d88: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C0D88u;
    {
        const bool branch_taken_0x1c0d88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0D88u;
            // 0x1c0d8c: 0xae200024  sw          $zero, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0d88) {
            ctx->pc = 0x1C0D9Cu;
            goto label_1c0d9c;
        }
    }
    ctx->pc = 0x1C0D90u;
label_1c0d90:
    // 0x1c0d90: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c0d90u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c0d94: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0d94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0d98: 0xae220024  sw          $v0, 0x24($s1)
    ctx->pc = 0x1c0d98u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
label_1c0d9c:
    // 0x1c0d9c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c0d9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1c0da0:
    // 0x1c0da0: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C0DA0u;
    SET_GPR_U32(ctx, 31, 0x1C0DA8u);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0DA8u; }
        if (ctx->pc != 0x1C0DA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0DA8u; }
        if (ctx->pc != 0x1C0DA8u) { return; }
    }
    ctx->pc = 0x1C0DA8u;
label_1c0da8:
    // 0x1c0da8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c0da8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c0dac: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c0dacu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c0db0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c0db0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c0db4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0DB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0DB4u;
            // 0x1c0db8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0A54u: goto label_1c0a54;
            case 0x1C0AD4u: goto label_1c0ad4;
            case 0x1C0ADCu: goto label_1c0adc;
            case 0x1C0B0Cu: goto label_1c0b0c;
            case 0x1C0B18u: goto label_1c0b18;
            case 0x1C0B24u: goto label_1c0b24;
            case 0x1C0B38u: goto label_1c0b38;
            case 0x1C0B4Cu: goto label_1c0b4c;
            case 0x1C0B58u: goto label_1c0b58;
            case 0x1C0B60u: goto label_1c0b60;
            case 0x1C0B7Cu: goto label_1c0b7c;
            case 0x1C0B90u: goto label_1c0b90;
            case 0x1C0BA0u: goto label_1c0ba0;
            case 0x1C0BDCu: goto label_1c0bdc;
            case 0x1C0BF8u: goto label_1c0bf8;
            case 0x1C0C18u: goto label_1c0c18;
            case 0x1C0C20u: goto label_1c0c20;
            case 0x1C0C4Cu: goto label_1c0c4c;
            case 0x1C0C6Cu: goto label_1c0c6c;
            case 0x1C0C88u: goto label_1c0c88;
            case 0x1C0C98u: goto label_1c0c98;
            case 0x1C0CA8u: goto label_1c0ca8;
            case 0x1C0CB8u: goto label_1c0cb8;
            case 0x1C0CC0u: goto label_1c0cc0;
            case 0x1C0CDCu: goto label_1c0cdc;
            case 0x1C0CECu: goto label_1c0cec;
            case 0x1C0CFCu: goto label_1c0cfc;
            case 0x1C0D04u: goto label_1c0d04;
            case 0x1C0D20u: goto label_1c0d20;
            case 0x1C0D30u: goto label_1c0d30;
            case 0x1C0D40u: goto label_1c0d40;
            case 0x1C0D48u: goto label_1c0d48;
            case 0x1C0D64u: goto label_1c0d64;
            case 0x1C0D84u: goto label_1c0d84;
            case 0x1C0D90u: goto label_1c0d90;
            case 0x1C0D9Cu: goto label_1c0d9c;
            case 0x1C0DA0u: goto label_1c0da0;
            case 0x1C0DA8u: goto label_1c0da8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C0DBCu;
    // 0x1c0dbc: 0x0  nop
    ctx->pc = 0x1c0dbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
