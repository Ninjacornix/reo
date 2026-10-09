#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B28B0
// Address: 0x1b28b0 - 0x1b298c
void sub_001B28B0_0x1b28b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B28B0_0x1b28b0");
#endif

    switch (ctx->pc) {
        case 0x1b28ecu: goto label_1b28ec;
        case 0x1b28fcu: goto label_1b28fc;
        case 0x1b2904u: goto label_1b2904;
        case 0x1b292cu: goto label_1b292c;
        case 0x1b2940u: goto label_1b2940;
        case 0x1b2960u: goto label_1b2960;
        default: break;
    }

    ctx->pc = 0x1b28b0u;

    // 0x1b28b0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1b28b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1b28b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b28b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b28b8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1b28b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1b28bc: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b28bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b28c0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b28c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b28c4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b28c4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b28c8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b28c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b28cc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b28ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b28d0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b28d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b28d4: 0x902243d3  lbu         $v0, 0x43D3($at)
    ctx->pc = 0x1b28d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17363)));
    // 0x1b28d8: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1b28d8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1b28dc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B28DCu;
    {
        const bool branch_taken_0x1b28dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B28E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B28DCu;
            // 0x1b28e0: 0x26108ea0  addiu       $s0, $s0, -0x7160 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294938272));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b28dc) {
            ctx->pc = 0x1B28ECu;
            goto label_1b28ec;
        }
    }
    ctx->pc = 0x1B28E4u;
    // 0x1b28e4: 0xc06be14  jal         func_1AF850
    ctx->pc = 0x1B28E4u;
    SET_GPR_U32(ctx, 31, 0x1B28ECu);
    ctx->pc = 0x1B28E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B28E4u;
            // 0x1b28e8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF850u;
    if (runtime->hasFunction(0x1AF850u)) {
        auto targetFn = runtime->lookupFunction(0x1AF850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B28ECu; }
        if (ctx->pc != 0x1B28ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF850_0x1af850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B28ECu; }
        if (ctx->pc != 0x1B28ECu) { return; }
    }
    ctx->pc = 0x1B28ECu;
label_1b28ec:
    // 0x1b28ec: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b28ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b28f0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b28f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b28f4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B28F4u;
    SET_GPR_U32(ctx, 31, 0x1B28FCu);
    ctx->pc = 0x1B28F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B28F4u;
            // 0x1b28f8: 0x2406033c  addiu       $a2, $zero, 0x33C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 828));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B28FCu; }
        if (ctx->pc != 0x1B28FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B28FCu; }
        if (ctx->pc != 0x1B28FCu) { return; }
    }
    ctx->pc = 0x1B28FCu;
label_1b28fc:
    // 0x1b28fc: 0xc06bde8  jal         func_1AF7A0
    ctx->pc = 0x1B28FCu;
    SET_GPR_U32(ctx, 31, 0x1B2904u);
    ctx->pc = 0x1B2900u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B28FCu;
            // 0x1b2900: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF7A0u;
    if (runtime->hasFunction(0x1AF7A0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF7A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2904u; }
        if (ctx->pc != 0x1B2904u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF7A0_0x1af7a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2904u; }
        if (ctx->pc != 0x1B2904u) { return; }
    }
    ctx->pc = 0x1B2904u;
label_1b2904:
    // 0x1b2904: 0x1118c0  sll         $v1, $s1, 3
    ctx->pc = 0x1b2904u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x1b2908: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x1b2908u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x1b290c: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1b290cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1b2910: 0x3442b680  ori         $v0, $v0, 0xB680
    ctx->pc = 0x1b2910u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46720);
    // 0x1b2914: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1b2914u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b2918: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1b2918u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1b291c: 0x390c0  sll         $s2, $v1, 3
    ctx->pc = 0x1b291cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1b2920: 0x2429821  addu        $s3, $s2, $v0
    ctx->pc = 0x1b2920u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1b2924: 0xc06bdc4  jal         func_1AF710
    ctx->pc = 0x1B2924u;
    SET_GPR_U32(ctx, 31, 0x1B292Cu);
    ctx->pc = 0x1B2928u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2924u;
            // 0x1b2928: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF710u;
    if (runtime->hasFunction(0x1AF710u)) {
        auto targetFn = runtime->lookupFunction(0x1AF710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B292Cu; }
        if (ctx->pc != 0x1B292Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF710_0x1af710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B292Cu; }
        if (ctx->pc != 0x1B292Cu) { return; }
    }
    ctx->pc = 0x1B292Cu;
label_1b292c:
    // 0x1b292c: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x1b292cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2930: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1b2930u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2934: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1b2934u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2938: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B2938u;
    SET_GPR_U32(ctx, 31, 0x1B2940u);
    ctx->pc = 0x1B293Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2938u;
            // 0x1b293c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2940u; }
        if (ctx->pc != 0x1B2940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2940u; }
        if (ctx->pc != 0x1B2940u) { return; }
    }
    ctx->pc = 0x1B2940u;
label_1b2940:
    // 0x1b2940: 0x2921021  addu        $v0, $s4, $s2
    ctx->pc = 0x1b2940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
    // 0x1b2944: 0xae140010  sw          $s4, 0x10($s0)
    ctx->pc = 0x1b2944u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 20));
    // 0x1b2948: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x1b2948u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x1b294c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b294cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2950: 0xa6110008  sh          $s1, 0x8($s0)
    ctx->pc = 0x1b2950u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 17));
    // 0x1b2954: 0xa600000a  sh          $zero, 0xA($s0)
    ctx->pc = 0x1b2954u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b2958: 0xc07395c  jal         func_1CE570
    ctx->pc = 0x1B2958u;
    SET_GPR_U32(ctx, 31, 0x1B2960u);
    ctx->pc = 0x1B295Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2958u;
            // 0x1b295c: 0xa600000c  sh          $zero, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE570u;
    if (runtime->hasFunction(0x1CE570u)) {
        auto targetFn = runtime->lookupFunction(0x1CE570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2960u; }
        if (ctx->pc != 0x1B2960u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE570_0x1ce570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2960u; }
        if (ctx->pc != 0x1B2960u) { return; }
    }
    ctx->pc = 0x1B2960u;
label_1b2960:
    // 0x1b2960: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b2960u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b2964: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b2964u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2968: 0xa02343d3  sb          $v1, 0x43D3($at)
    ctx->pc = 0x1b2968u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17363), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b296c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1b296cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b2970: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b2970u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b2974: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b2974u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b2978: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b2978u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b297c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b297cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b2980: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b2980u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2984: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2984u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2984u;
            // 0x1b2988: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B28ECu: goto label_1b28ec;
            case 0x1B28FCu: goto label_1b28fc;
            case 0x1B2904u: goto label_1b2904;
            case 0x1B292Cu: goto label_1b292c;
            case 0x1B2940u: goto label_1b2940;
            case 0x1B2960u: goto label_1b2960;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B298Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
