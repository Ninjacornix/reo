#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC260
// Address: 0x1cc260 - 0x1cc550
void sub_001CC260_0x1cc260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC260_0x1cc260");
#endif

    switch (ctx->pc) {
        case 0x1cc28cu: goto label_1cc28c;
        case 0x1cc29cu: goto label_1cc29c;
        case 0x1cc2c0u: goto label_1cc2c0;
        case 0x1cc32cu: goto label_1cc32c;
        case 0x1cc34cu: goto label_1cc34c;
        case 0x1cc354u: goto label_1cc354;
        case 0x1cc36cu: goto label_1cc36c;
        case 0x1cc4e0u: goto label_1cc4e0;
        case 0x1cc510u: goto label_1cc510;
        case 0x1cc53cu: goto label_1cc53c;
        default: break;
    }

    ctx->pc = 0x1cc260u;

    // 0x1cc260: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1cc260u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1cc264: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cc264u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cc268: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cc268u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cc26c: 0x24420a40  addiu       $v0, $v0, 0xA40
    ctx->pc = 0x1cc26cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2624));
    // 0x1cc270: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc270u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc274: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cc274u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc278: 0xac220a20  sw          $v0, 0xA20($at)
    ctx->pc = 0x1cc278u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2592), GPR_U32(ctx, 2));
    // 0x1cc27c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc27cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc280: 0x8c240a20  lw          $a0, 0xA20($at)
    ctx->pc = 0x1cc280u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2592)));
    // 0x1cc284: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CC284u;
    SET_GPR_U32(ctx, 31, 0x1CC28Cu);
    ctx->pc = 0x1CC288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC284u;
            // 0x1cc288: 0x24060098  addiu       $a2, $zero, 0x98 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 152));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC28Cu; }
        if (ctx->pc != 0x1CC28Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC28Cu; }
        if (ctx->pc != 0x1CC28Cu) { return; }
    }
    ctx->pc = 0x1CC28Cu;
label_1cc28c:
    // 0x1cc28c: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1cc28cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1cc290: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cc290u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc294: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CC294u;
    SET_GPR_U32(ctx, 31, 0x1CC29Cu);
    ctx->pc = 0x1CC298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC294u;
            // 0x1cc298: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC29Cu; }
        if (ctx->pc != 0x1CC29Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC29Cu; }
        if (ctx->pc != 0x1CC29Cu) { return; }
    }
    ctx->pc = 0x1CC29Cu;
label_1cc29c:
    // 0x1cc29c: 0x3c010025  lui         $at, 0x25
    ctx->pc = 0x1cc29cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)37 << 16));
    // 0x1cc2a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cc2a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cc2a4: 0xc4202ea0  lwc1        $f0, 0x2EA0($at)
    ctx->pc = 0x1cc2a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 11936)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1cc2a8: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x1cc2a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x1cc2ac: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1cc2acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1cc2b0: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x1cc2b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x1cc2b4: 0xa3a0001c  sb          $zero, 0x1C($sp)
    ctx->pc = 0x1cc2b4u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 28), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cc2b8: 0xc0579a8  jal         func_15E6A0
    ctx->pc = 0x1CC2B8u;
    SET_GPR_U32(ctx, 31, 0x1CC2C0u);
    ctx->pc = 0x1CC2BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC2B8u;
            // 0x1cc2bc: 0xe7a00010  swc1        $f0, 0x10($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E6A0u;
    if (runtime->hasFunction(0x15E6A0u)) {
        auto targetFn = runtime->lookupFunction(0x15E6A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC2C0u; }
        if (ctx->pc != 0x1CC2C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E6A0_0x15e6a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC2C0u; }
        if (ctx->pc != 0x1CC2C0u) { return; }
    }
    ctx->pc = 0x1CC2C0u;
label_1cc2c0:
    // 0x1cc2c0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cc2c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cc2c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC2C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC2C4u;
            // 0x1cc2c8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC28Cu: goto label_1cc28c;
            case 0x1CC29Cu: goto label_1cc29c;
            case 0x1CC2C0u: goto label_1cc2c0;
            case 0x1CC32Cu: goto label_1cc32c;
            case 0x1CC34Cu: goto label_1cc34c;
            case 0x1CC354u: goto label_1cc354;
            case 0x1CC36Cu: goto label_1cc36c;
            case 0x1CC4E0u: goto label_1cc4e0;
            case 0x1CC4E8u: goto label_1cc4e8;
            case 0x1CC510u: goto label_1cc510;
            case 0x1CC51Cu: goto label_1cc51c;
            case 0x1CC53Cu: goto label_1cc53c;
            case 0x1CC540u: goto label_1cc540;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC2CCu;
    // 0x1cc2cc: 0x0  nop
    ctx->pc = 0x1cc2ccu;
    // NOP
    // 0x1cc2d0: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x1cc2d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x1cc2d4: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cc2d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cc2d8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1cc2d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1cc2dc: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1cc2dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1cc2e0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cc2e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cc2e4: 0x24420a40  addiu       $v0, $v0, 0xA40
    ctx->pc = 0x1cc2e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2624));
    // 0x1cc2e8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cc2e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cc2ec: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1cc2ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc2f0: 0x8c23ac38  lw          $v1, -0x53C8($at)
    ctx->pc = 0x1cc2f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945848)));
    // 0x1cc2f4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cc2f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc2f8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc2f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc2fc: 0xac220a20  sw          $v0, 0xA20($at)
    ctx->pc = 0x1cc2fcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2592), GPR_U32(ctx, 2));
    // 0x1cc300: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc300u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc304: 0x8c220a20  lw          $v0, 0xA20($at)
    ctx->pc = 0x1cc304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2592)));
    // 0x1cc308: 0xac430084  sw          $v1, 0x84($v0)
    ctx->pc = 0x1cc308u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 132), GPR_U32(ctx, 3));
    // 0x1cc30c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1cc30cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1cc310: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1cc310u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1cc314: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc314u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc318: 0xac300a30  sw          $s0, 0xA30($at)
    ctx->pc = 0x1cc318u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2608), GPR_U32(ctx, 16));
    // 0x1cc31c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc31cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc320: 0x8c240a30  lw          $a0, 0xA30($at)
    ctx->pc = 0x1cc320u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc324: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CC324u;
    SET_GPR_U32(ctx, 31, 0x1CC32Cu);
    ctx->pc = 0x1CC328u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC324u;
            // 0x1cc328: 0x24060064  addiu       $a2, $zero, 0x64 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC32Cu; }
        if (ctx->pc != 0x1CC32Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC32Cu; }
        if (ctx->pc != 0x1CC32Cu) { return; }
    }
    ctx->pc = 0x1CC32Cu;
label_1cc32c:
    // 0x1cc32c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cc32cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cc330: 0x260300a3  addiu       $v1, $s0, 0xA3
    ctx->pc = 0x1cc330u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 163));
    // 0x1cc334: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x1cc334u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1cc338: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1cc338u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc33c: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1cc33cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1cc340: 0x628024  and         $s0, $v1, $v0
    ctx->pc = 0x1cc340u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1cc344: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CC344u;
    SET_GPR_U32(ctx, 31, 0x1CC34Cu);
    ctx->pc = 0x1CC348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC344u;
            // 0x1cc348: 0x24a52e80  addiu       $a1, $a1, 0x2E80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11904));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC34Cu; }
        if (ctx->pc != 0x1CC34Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC34Cu; }
        if (ctx->pc != 0x1CC34Cu) { return; }
    }
    ctx->pc = 0x1CC34Cu;
label_1cc34c:
    // 0x1cc34c: 0xc0636ac  jal         func_18DAB0
    ctx->pc = 0x1CC34Cu;
    SET_GPR_U32(ctx, 31, 0x1CC354u);
    ctx->pc = 0x1CC350u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC34Cu;
            // 0x1cc350: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DAB0u;
    if (runtime->hasFunction(0x18DAB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DAB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC354u; }
        if (ctx->pc != 0x1CC354u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DAB0_0x18dab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC354u; }
        if (ctx->pc != 0x1CC354u) { return; }
    }
    ctx->pc = 0x1CC354u;
label_1cc354:
    // 0x1cc354: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1cc354u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc358: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1cc358u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1cc35c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1cc35cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc360: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1cc360u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cc364: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1CC364u;
    SET_GPR_U32(ctx, 31, 0x1CC36Cu);
    ctx->pc = 0x1CC368u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC364u;
            // 0x1cc368: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC36Cu; }
        if (ctx->pc != 0x1CC36Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC36Cu; }
        if (ctx->pc != 0x1CC36Cu) { return; }
    }
    ctx->pc = 0x1CC36Cu;
label_1cc36c:
    // 0x1cc36c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc36cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc370: 0x2111821  addu        $v1, $s0, $s1
    ctx->pc = 0x1cc370u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x1cc374: 0x8c250a30  lw          $a1, 0xA30($at)
    ctx->pc = 0x1cc374u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc378: 0x2463003f  addiu       $v1, $v1, 0x3F
    ctx->pc = 0x1cc378u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
    // 0x1cc37c: 0x2407ffc0  addiu       $a3, $zero, -0x40
    ctx->pc = 0x1cc37cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1cc380: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1cc380u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cc384: 0x674024  and         $t0, $v1, $a3
    ctx->pc = 0x1cc384u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 3) & GPR_U64(ctx, 7));
    // 0x1cc388: 0x2503007f  addiu       $v1, $t0, 0x7F
    ctx->pc = 0x1cc388u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 127));
    // 0x1cc38c: 0x671824  and         $v1, $v1, $a3
    ctx->pc = 0x1cc38cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 7));
    // 0x1cc390: 0xacb00004  sw          $s0, 0x4($a1)
    ctx->pc = 0x1cc390u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 16));
    // 0x1cc394: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc394u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc398: 0x8e060004  lw          $a2, 0x4($s0)
    ctx->pc = 0x1cc398u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cc39c: 0x8c250a30  lw          $a1, 0xA30($at)
    ctx->pc = 0x1cc39cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc3a0: 0x24c6fff8  addiu       $a2, $a2, -0x8
    ctx->pc = 0x1cc3a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967288));
    // 0x1cc3a4: 0xaca60008  sw          $a2, 0x8($a1)
    ctx->pc = 0x1cc3a4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 6));
    // 0x1cc3a8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc3a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc3ac: 0x8c250a30  lw          $a1, 0xA30($at)
    ctx->pc = 0x1cc3acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc3b0: 0x86060008  lh          $a2, 0x8($s0)
    ctx->pc = 0x1cc3b0u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1cc3b4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc3b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc3b8: 0xaca6000c  sw          $a2, 0xC($a1)
    ctx->pc = 0x1cc3b8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 6));
    // 0x1cc3bc: 0x8c250a30  lw          $a1, 0xA30($at)
    ctx->pc = 0x1cc3bcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc3c0: 0x8606000a  lh          $a2, 0xA($s0)
    ctx->pc = 0x1cc3c0u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1cc3c4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc3c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc3c8: 0xaca60010  sw          $a2, 0x10($a1)
    ctx->pc = 0x1cc3c8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 6));
    // 0x1cc3cc: 0x8c250a30  lw          $a1, 0xA30($at)
    ctx->pc = 0x1cc3ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc3d0: 0x8e06000c  lw          $a2, 0xC($s0)
    ctx->pc = 0x1cc3d0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1cc3d4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc3d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc3d8: 0xaca60014  sw          $a2, 0x14($a1)
    ctx->pc = 0x1cc3d8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 6));
    // 0x1cc3dc: 0x8c250a30  lw          $a1, 0xA30($at)
    ctx->pc = 0x1cc3dcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc3e0: 0xaca00018  sw          $zero, 0x18($a1)
    ctx->pc = 0x1cc3e0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 0));
    // 0x1cc3e4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc3e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc3e8: 0x8c260a30  lw          $a2, 0xA30($at)
    ctx->pc = 0x1cc3e8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc3ec: 0x8cc5000c  lw          $a1, 0xC($a2)
    ctx->pc = 0x1cc3ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x1cc3f0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc3f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc3f4: 0x52902  srl         $a1, $a1, 4
    ctx->pc = 0x1cc3f4u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 4));
    // 0x1cc3f8: 0xacc5001c  sw          $a1, 0x1C($a2)
    ctx->pc = 0x1cc3f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 5));
    // 0x1cc3fc: 0x8c260a30  lw          $a2, 0xA30($at)
    ctx->pc = 0x1cc3fcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc400: 0x8cc50010  lw          $a1, 0x10($a2)
    ctx->pc = 0x1cc400u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x1cc404: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc404u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc408: 0x52902  srl         $a1, $a1, 4
    ctx->pc = 0x1cc408u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 4));
    // 0x1cc40c: 0xacc50020  sw          $a1, 0x20($a2)
    ctx->pc = 0x1cc40cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 5));
    // 0x1cc410: 0x8c250a30  lw          $a1, 0xA30($at)
    ctx->pc = 0x1cc410u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc414: 0xaca80028  sw          $t0, 0x28($a1)
    ctx->pc = 0x1cc414u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 40), GPR_U32(ctx, 8));
    // 0x1cc418: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc418u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc41c: 0x8c250a30  lw          $a1, 0xA30($at)
    ctx->pc = 0x1cc41cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc420: 0xaca3002c  sw          $v1, 0x2C($a1)
    ctx->pc = 0x1cc420u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 44), GPR_U32(ctx, 3));
    // 0x1cc424: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc424u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc428: 0x8c280a30  lw          $t0, 0xA30($at)
    ctx->pc = 0x1cc428u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc42c: 0x8d06000c  lw          $a2, 0xC($t0)
    ctx->pc = 0x1cc42cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 12)));
    // 0x1cc430: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc430u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc434: 0x8d050010  lw          $a1, 0x10($t0)
    ctx->pc = 0x1cc434u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 16)));
    // 0x1cc438: 0xc53018  mult        $a2, $a2, $a1
    ctx->pc = 0x1cc438u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x1cc43c: 0xad000000  sw          $zero, 0x0($t0)
    ctx->pc = 0x1cc43cu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 0));
    // 0x1cc440: 0x8c250a30  lw          $a1, 0xA30($at)
    ctx->pc = 0x1cc440u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc444: 0x64080  sll         $t0, $a2, 2
    ctx->pc = 0x1cc444u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1cc448: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x1cc448u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x1cc44c: 0x2463003f  addiu       $v1, $v1, 0x3F
    ctx->pc = 0x1cc44cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
    // 0x1cc450: 0x671824  and         $v1, $v1, $a3
    ctx->pc = 0x1cc450u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 7));
    // 0x1cc454: 0xaca30030  sw          $v1, 0x30($a1)
    ctx->pc = 0x1cc454u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 48), GPR_U32(ctx, 3));
    // 0x1cc458: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc458u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc45c: 0x8c250a30  lw          $a1, 0xA30($at)
    ctx->pc = 0x1cc45cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc460: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x1cc460u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x1cc464: 0x2463003f  addiu       $v1, $v1, 0x3F
    ctx->pc = 0x1cc464u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
    // 0x1cc468: 0x673024  and         $a2, $v1, $a3
    ctx->pc = 0x1cc468u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & GPR_U64(ctx, 7));
    // 0x1cc46c: 0xc81821  addu        $v1, $a2, $t0
    ctx->pc = 0x1cc46cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x1cc470: 0x2463003f  addiu       $v1, $v1, 0x3F
    ctx->pc = 0x1cc470u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
    // 0x1cc474: 0x673824  and         $a3, $v1, $a3
    ctx->pc = 0x1cc474u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) & GPR_U64(ctx, 7));
    // 0x1cc478: 0xaca60034  sw          $a2, 0x34($a1)
    ctx->pc = 0x1cc478u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 52), GPR_U32(ctx, 6));
    // 0x1cc47c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc47cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc480: 0x8c230a30  lw          $v1, 0xA30($at)
    ctx->pc = 0x1cc480u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2608)));
    // 0x1cc484: 0xac67003c  sw          $a3, 0x3C($v1)
    ctx->pc = 0x1cc484u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 60), GPR_U32(ctx, 7));
    // 0x1cc488: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc488u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc48c: 0xac240a40  sw          $a0, 0xA40($at)
    ctx->pc = 0x1cc48cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2624), GPR_U32(ctx, 4));
    // 0x1cc490: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1cc490u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cc494: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cc494u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cc498: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cc498u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cc49c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC49Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC4A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC49Cu;
            // 0x1cc4a0: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC28Cu: goto label_1cc28c;
            case 0x1CC29Cu: goto label_1cc29c;
            case 0x1CC2C0u: goto label_1cc2c0;
            case 0x1CC32Cu: goto label_1cc32c;
            case 0x1CC34Cu: goto label_1cc34c;
            case 0x1CC354u: goto label_1cc354;
            case 0x1CC36Cu: goto label_1cc36c;
            case 0x1CC4E0u: goto label_1cc4e0;
            case 0x1CC4E8u: goto label_1cc4e8;
            case 0x1CC510u: goto label_1cc510;
            case 0x1CC51Cu: goto label_1cc51c;
            case 0x1CC53Cu: goto label_1cc53c;
            case 0x1CC540u: goto label_1cc540;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC4A4u;
    // 0x1cc4a4: 0x0  nop
    ctx->pc = 0x1cc4a4u;
    // NOP
    // 0x1cc4a8: 0x0  nop
    ctx->pc = 0x1cc4a8u;
    // NOP
    // 0x1cc4ac: 0x0  nop
    ctx->pc = 0x1cc4acu;
    // NOP
    // 0x1cc4b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cc4b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cc4b4: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1cc4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1cc4b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cc4b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cc4bc: 0x24630a40  addiu       $v1, $v1, 0xA40
    ctx->pc = 0x1cc4bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2624));
    // 0x1cc4c0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc4c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc4c4: 0xac230a20  sw          $v1, 0xA20($at)
    ctx->pc = 0x1cc4c4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2592), GPR_U32(ctx, 3));
    // 0x1cc4c8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1cc4c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1cc4cc: 0x902343d5  lbu         $v1, 0x43D5($at)
    ctx->pc = 0x1cc4ccu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17365)));
    // 0x1cc4d0: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CC4D0u;
    {
        const bool branch_taken_0x1cc4d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CC4D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC4D0u;
            // 0x1cc4d4: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc4d0) {
            ctx->pc = 0x1CC4E8u;
            goto label_1cc4e8;
        }
    }
    ctx->pc = 0x1CC4D8u;
    // 0x1cc4d8: 0xc0de938  jal         func_37A4E0
    ctx->pc = 0x1CC4D8u;
    SET_GPR_U32(ctx, 31, 0x1CC4E0u);
    ctx->pc = 0x37A4E0u;
    {
        auto targetFn = runtime->lookupFunction(0x37A4E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC4E0u; }
        if (ctx->pc != 0x1CC4E0u) { return; }
    }
    ctx->pc = 0x1CC4E0u;
label_1cc4e0:
    // 0x1cc4e0: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1CC4E0u;
    {
        const bool branch_taken_0x1cc4e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CC4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC4E0u;
            // 0x1cc4e4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc4e0) {
            ctx->pc = 0x1CC540u;
            goto label_1cc540;
        }
    }
    ctx->pc = 0x1CC4E8u;
label_1cc4e8:
    // 0x1cc4e8: 0x8c240a20  lw          $a0, 0xA20($at)
    ctx->pc = 0x1cc4e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2592)));
    // 0x1cc4ec: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1cc4ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1cc4f0: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1CC4F0u;
    {
        const bool branch_taken_0x1cc4f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc4f0) {
            ctx->pc = 0x1CC53Cu;
            goto label_1cc53c;
        }
    }
    ctx->pc = 0x1CC4F8u;
    // 0x1cc4f8: 0x8c820084  lw          $v0, 0x84($a0)
    ctx->pc = 0x1cc4f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 132)));
    // 0x1cc4fc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CC4FCu;
    {
        const bool branch_taken_0x1cc4fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc4fc) {
            ctx->pc = 0x1CC51Cu;
            goto label_1cc51c;
        }
    }
    ctx->pc = 0x1CC504u;
    // 0x1cc504: 0x24040ff0  addiu       $a0, $zero, 0xFF0
    ctx->pc = 0x1cc504u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4080));
    // 0x1cc508: 0xc073420  jal         func_1CD080
    ctx->pc = 0x1CC508u;
    SET_GPR_U32(ctx, 31, 0x1CC510u);
    ctx->pc = 0x1CC50Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC508u;
            // 0x1cc50c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD080u;
    if (runtime->hasFunction(0x1CD080u)) {
        auto targetFn = runtime->lookupFunction(0x1CD080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC510u; }
        if (ctx->pc != 0x1CC510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC510u; }
        if (ctx->pc != 0x1CC510u) { return; }
    }
    ctx->pc = 0x1CC510u;
label_1cc510:
    // 0x1cc510: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc510u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc514: 0x8c220a20  lw          $v0, 0xA20($at)
    ctx->pc = 0x1cc514u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2592)));
    // 0x1cc518: 0xac400084  sw          $zero, 0x84($v0)
    ctx->pc = 0x1cc518u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 132), GPR_U32(ctx, 0));
label_1cc51c:
    // 0x1cc51c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc51cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc520: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cc520u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cc524: 0x8c220a20  lw          $v0, 0xA20($at)
    ctx->pc = 0x1cc524u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2592)));
    // 0x1cc528: 0x24840a40  addiu       $a0, $a0, 0xA40
    ctx->pc = 0x1cc528u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2624));
    // 0x1cc52c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cc52cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc530: 0x24060098  addiu       $a2, $zero, 0x98
    ctx->pc = 0x1cc530u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 152));
    // 0x1cc534: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CC534u;
    SET_GPR_U32(ctx, 31, 0x1CC53Cu);
    ctx->pc = 0x1CC538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC534u;
            // 0x1cc538: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC53Cu; }
        if (ctx->pc != 0x1CC53Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC53Cu; }
        if (ctx->pc != 0x1CC53Cu) { return; }
    }
    ctx->pc = 0x1CC53Cu;
label_1cc53c:
    // 0x1cc53c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cc53cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1cc540:
    // 0x1cc540: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC540u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC540u;
            // 0x1cc544: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC28Cu: goto label_1cc28c;
            case 0x1CC29Cu: goto label_1cc29c;
            case 0x1CC2C0u: goto label_1cc2c0;
            case 0x1CC32Cu: goto label_1cc32c;
            case 0x1CC34Cu: goto label_1cc34c;
            case 0x1CC354u: goto label_1cc354;
            case 0x1CC36Cu: goto label_1cc36c;
            case 0x1CC4E0u: goto label_1cc4e0;
            case 0x1CC4E8u: goto label_1cc4e8;
            case 0x1CC510u: goto label_1cc510;
            case 0x1CC51Cu: goto label_1cc51c;
            case 0x1CC53Cu: goto label_1cc53c;
            case 0x1CC540u: goto label_1cc540;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC548u;
    // 0x1cc548: 0x0  nop
    ctx->pc = 0x1cc548u;
    // NOP
    // 0x1cc54c: 0x0  nop
    ctx->pc = 0x1cc54cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
