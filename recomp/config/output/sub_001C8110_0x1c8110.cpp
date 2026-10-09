#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8110
// Address: 0x1c8110 - 0x1c82d0
void sub_001C8110_0x1c8110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8110_0x1c8110");
#endif

    switch (ctx->pc) {
        case 0x1c8120u: goto label_1c8120;
        case 0x1c8140u: goto label_1c8140;
        case 0x1c8148u: goto label_1c8148;
        case 0x1c8178u: goto label_1c8178;
        case 0x1c8184u: goto label_1c8184;
        case 0x1c823cu: goto label_1c823c;
        case 0x1c8258u: goto label_1c8258;
        case 0x1c8278u: goto label_1c8278;
        case 0x1c8298u: goto label_1c8298;
        case 0x1c82b4u: goto label_1c82b4;
        case 0x1c82bcu: goto label_1c82bc;
        default: break;
    }

    ctx->pc = 0x1c8110u;

label_1c8110:
    // 0x1c8110: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c8110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c8114: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8114u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8118: 0xc0759a4  jal         func_1D6690
    ctx->pc = 0x1C8118u;
    SET_GPR_U32(ctx, 31, 0x1C8120u);
    ctx->pc = 0x1D6690u;
    if (runtime->hasFunction(0x1D6690u)) {
        auto targetFn = runtime->lookupFunction(0x1D6690u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8120u; }
        if (ctx->pc != 0x1C8120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6690_0x1d6690(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8120u; }
        if (ctx->pc != 0x1C8120u) { return; }
    }
    ctx->pc = 0x1C8120u;
label_1c8120:
    // 0x1c8120: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8120u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8124: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c8124u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8128: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8128u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C812Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8128u;
            // 0x1c812c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8110u: goto label_1c8110;
            case 0x1C8120u: goto label_1c8120;
            case 0x1C8140u: goto label_1c8140;
            case 0x1C8148u: goto label_1c8148;
            case 0x1C8178u: goto label_1c8178;
            case 0x1C8184u: goto label_1c8184;
            case 0x1C81FCu: goto label_1c81fc;
            case 0x1C823Cu: goto label_1c823c;
            case 0x1C8258u: goto label_1c8258;
            case 0x1C8278u: goto label_1c8278;
            case 0x1C8298u: goto label_1c8298;
            case 0x1C82B4u: goto label_1c82b4;
            case 0x1C82BCu: goto label_1c82bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8130u;
    // 0x1c8130: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c8130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c8134: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8138: 0xc072358  jal         func_1C8D60
    ctx->pc = 0x1C8138u;
    SET_GPR_U32(ctx, 31, 0x1C8140u);
    ctx->pc = 0x1C8D60u;
    if (runtime->hasFunction(0x1C8D60u)) {
        auto targetFn = runtime->lookupFunction(0x1C8D60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8140u; }
        if (ctx->pc != 0x1C8140u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8D60_0x1c8d60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8140u; }
        if (ctx->pc != 0x1C8140u) { return; }
    }
    ctx->pc = 0x1C8140u;
label_1c8140:
    // 0x1c8140: 0xc072020  jal         func_1C8080
    ctx->pc = 0x1C8140u;
    SET_GPR_U32(ctx, 31, 0x1C8148u);
    ctx->pc = 0x1C8080u;
    if (runtime->hasFunction(0x1C8080u)) {
        auto targetFn = runtime->lookupFunction(0x1C8080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8148u; }
        if (ctx->pc != 0x1C8148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8080_0x1c8080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8148u; }
        if (ctx->pc != 0x1C8148u) { return; }
    }
    ctx->pc = 0x1C8148u;
label_1c8148:
    // 0x1c8148: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c8148u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c814c: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1c814cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1c8150: 0xac2051f0  sw          $zero, 0x51F0($at)
    ctx->pc = 0x1c8150u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20976), GPR_U32(ctx, 0));
    // 0x1c8154: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1c8154u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c8158: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c8158u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c815c: 0x24c62db0  addiu       $a2, $a2, 0x2DB0
    ctx->pc = 0x1c815cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 11696));
    // 0x1c8160: 0xac2051f8  sw          $zero, 0x51F8($at)
    ctx->pc = 0x1c8160u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20984), GPR_U32(ctx, 0));
    // 0x1c8164: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1c8164u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8168: 0x3c010081  lui         $at, 0x81
    ctx->pc = 0x1c8168u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)129 << 16));
    // 0x1c816c: 0x8c244848  lw          $a0, 0x4848($at)
    ctx->pc = 0x1c816cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18504)));
    // 0x1c8170: 0xc071fb4  jal         func_1C7ED0
    ctx->pc = 0x1C8170u;
    SET_GPR_U32(ctx, 31, 0x1C8178u);
    ctx->pc = 0x1C8174u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8170u;
            // 0x1c8174: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7ED0u;
    if (runtime->hasFunction(0x1C7ED0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8178u; }
        if (ctx->pc != 0x1C8178u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7ED0_0x1c7ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8178u; }
        if (ctx->pc != 0x1C8178u) { return; }
    }
    ctx->pc = 0x1C8178u;
label_1c8178:
    // 0x1c8178: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1c8178u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1c817c: 0xc0470f8  jal         func_11C3E0
    ctx->pc = 0x1C817Cu;
    SET_GPR_U32(ctx, 31, 0x1C8184u);
    ctx->pc = 0x1C8180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C817Cu;
            // 0x1c8180: 0x24842db8  addiu       $a0, $a0, 0x2DB8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11704));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C3E0u;
    if (runtime->hasFunction(0x11C3E0u)) {
        auto targetFn = runtime->lookupFunction(0x11C3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8184u; }
        if (ctx->pc != 0x1C8184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C3E0_0x11c3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8184u; }
        if (ctx->pc != 0x1C8184u) { return; }
    }
    ctx->pc = 0x1C8184u;
label_1c8184:
    // 0x1c8184: 0x40082a  slt         $at, $v0, $zero
    ctx->pc = 0x1c8184u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
    // 0x1c8188: 0x1420001c  bnez        $at, . + 4 + (0x1C << 2)
    ctx->pc = 0x1C8188u;
    {
        const bool branch_taken_0x1c8188 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c8188) {
            ctx->pc = 0x1C81FCu;
            goto label_1c81fc;
        }
    }
    ctx->pc = 0x1C8190u;
    // 0x1c8190: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c8190u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c8194: 0x24020021  addiu       $v0, $zero, 0x21
    ctx->pc = 0x1c8194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x1c8198: 0x8c275fa0  lw          $a3, 0x5FA0($at)
    ctx->pc = 0x1c8198u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24480)));
    // 0x1c819c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c819cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c81a0: 0xac22d148  sw          $v0, -0x2EB8($at)
    ctx->pc = 0x1c81a0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294955336), GPR_U32(ctx, 2));
    // 0x1c81a4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c81a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c81a8: 0x8c265fa4  lw          $a2, 0x5FA4($at)
    ctx->pc = 0x1c81a8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24484)));
    // 0x1c81ac: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c81acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c81b0: 0x8c255fa8  lw          $a1, 0x5FA8($at)
    ctx->pc = 0x1c81b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24488)));
    // 0x1c81b4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c81b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c81b8: 0x8c245fac  lw          $a0, 0x5FAC($at)
    ctx->pc = 0x1c81b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24492)));
    // 0x1c81bc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c81bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c81c0: 0x8c235fb4  lw          $v1, 0x5FB4($at)
    ctx->pc = 0x1c81c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24500)));
    // 0x1c81c4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c81c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c81c8: 0xac27d138  sw          $a3, -0x2EC8($at)
    ctx->pc = 0x1c81c8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294955320), GPR_U32(ctx, 7));
    // 0x1c81cc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c81ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c81d0: 0x8c225fb8  lw          $v0, 0x5FB8($at)
    ctx->pc = 0x1c81d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24504)));
    // 0x1c81d4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c81d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c81d8: 0xac26d13c  sw          $a2, -0x2EC4($at)
    ctx->pc = 0x1c81d8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294955324), GPR_U32(ctx, 6));
    // 0x1c81dc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c81dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c81e0: 0xac25d140  sw          $a1, -0x2EC0($at)
    ctx->pc = 0x1c81e0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294955328), GPR_U32(ctx, 5));
    // 0x1c81e4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c81e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c81e8: 0xac24d144  sw          $a0, -0x2EBC($at)
    ctx->pc = 0x1c81e8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294955332), GPR_U32(ctx, 4));
    // 0x1c81ec: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c81ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c81f0: 0xac23d14c  sw          $v1, -0x2EB4($at)
    ctx->pc = 0x1c81f0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294955340), GPR_U32(ctx, 3));
    // 0x1c81f4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c81f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c81f8: 0xac22d150  sw          $v0, -0x2EB0($at)
    ctx->pc = 0x1c81f8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294955344), GPR_U32(ctx, 2));
label_1c81fc:
    // 0x1c81fc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c81fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8200: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c8200u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c8204: 0x8c23d138  lw          $v1, -0x2EC8($at)
    ctx->pc = 0x1c8204u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955320)));
    // 0x1c8208: 0x1062002c  beq         $v1, $v0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1C8208u;
    {
        const bool branch_taken_0x1c8208 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C820Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8208u;
            // 0x1c820c: 0x3c010081  lui         $at, 0x81 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)129 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8208) {
            ctx->pc = 0x1C82BCu;
            goto label_1c82bc;
        }
    }
    ctx->pc = 0x1C8210u;
    // 0x1c8210: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1c8210u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1c8214: 0x8c244868  lw          $a0, 0x4868($at)
    ctx->pc = 0x1c8214u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18536)));
    // 0x1c8218: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1c8218u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1c821c: 0x2442d138  addiu       $v0, $v0, -0x2EC8
    ctx->pc = 0x1c821cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294955320));
    // 0x1c8220: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1c8220u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c8224: 0x24c62db0  addiu       $a2, $a2, 0x2DB0
    ctx->pc = 0x1c8224u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 11696));
    // 0x1c8228: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1c8228u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c822c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1c822cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8230: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8230u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8234: 0xc071fb4  jal         func_1C7ED0
    ctx->pc = 0x1C8234u;
    SET_GPR_U32(ctx, 31, 0x1C823Cu);
    ctx->pc = 0x1C8238u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8234u;
            // 0x1c8238: 0xac22d158  sw          $v0, -0x2EA8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294955352), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7ED0u;
    if (runtime->hasFunction(0x1C7ED0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C823Cu; }
        if (ctx->pc != 0x1C823Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7ED0_0x1c7ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C823Cu; }
        if (ctx->pc != 0x1C823Cu) { return; }
    }
    ctx->pc = 0x1C823Cu;
label_1c823c:
    // 0x1c823c: 0x3c010081  lui         $at, 0x81
    ctx->pc = 0x1c823cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)129 << 16));
    // 0x1c8240: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c8240u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8244: 0x8c244860  lw          $a0, 0x4860($at)
    ctx->pc = 0x1c8244u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18528)));
    // 0x1c8248: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1c8248u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c824c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1c824cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8250: 0xc071fb4  jal         func_1C7ED0
    ctx->pc = 0x1C8250u;
    SET_GPR_U32(ctx, 31, 0x1C8258u);
    ctx->pc = 0x1C8254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8250u;
            // 0x1c8254: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7ED0u;
    if (runtime->hasFunction(0x1C7ED0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8258u; }
        if (ctx->pc != 0x1C8258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7ED0_0x1c7ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8258u; }
        if (ctx->pc != 0x1C8258u) { return; }
    }
    ctx->pc = 0x1C8258u;
label_1c8258:
    // 0x1c8258: 0x3c010081  lui         $at, 0x81
    ctx->pc = 0x1c8258u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)129 << 16));
    // 0x1c825c: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1c825cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1c8260: 0x8c244850  lw          $a0, 0x4850($at)
    ctx->pc = 0x1c8260u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18512)));
    // 0x1c8264: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1c8264u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c8268: 0x24c62db0  addiu       $a2, $a2, 0x2DB0
    ctx->pc = 0x1c8268u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 11696));
    // 0x1c826c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1c826cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8270: 0xc071fb4  jal         func_1C7ED0
    ctx->pc = 0x1C8270u;
    SET_GPR_U32(ctx, 31, 0x1C8278u);
    ctx->pc = 0x1C8274u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8270u;
            // 0x1c8274: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7ED0u;
    if (runtime->hasFunction(0x1C7ED0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8278u; }
        if (ctx->pc != 0x1C8278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7ED0_0x1c7ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8278u; }
        if (ctx->pc != 0x1C8278u) { return; }
    }
    ctx->pc = 0x1C8278u;
label_1c8278:
    // 0x1c8278: 0x3c010081  lui         $at, 0x81
    ctx->pc = 0x1c8278u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)129 << 16));
    // 0x1c827c: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1c827cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1c8280: 0x8c244870  lw          $a0, 0x4870($at)
    ctx->pc = 0x1c8280u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18544)));
    // 0x1c8284: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x1c8284u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1c8288: 0x24c62dc0  addiu       $a2, $a2, 0x2DC0
    ctx->pc = 0x1c8288u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 11712));
    // 0x1c828c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1c828cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8290: 0xc071fb4  jal         func_1C7ED0
    ctx->pc = 0x1C8290u;
    SET_GPR_U32(ctx, 31, 0x1C8298u);
    ctx->pc = 0x1C8294u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8290u;
            // 0x1c8294: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7ED0u;
    if (runtime->hasFunction(0x1C7ED0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8298u; }
        if (ctx->pc != 0x1C8298u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7ED0_0x1c7ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8298u; }
        if (ctx->pc != 0x1C8298u) { return; }
    }
    ctx->pc = 0x1C8298u;
label_1c8298:
    // 0x1c8298: 0x3c010081  lui         $at, 0x81
    ctx->pc = 0x1c8298u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)129 << 16));
    // 0x1c829c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c829cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c82a0: 0x8c244858  lw          $a0, 0x4858($at)
    ctx->pc = 0x1c82a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18520)));
    // 0x1c82a4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1c82a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c82a8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1c82a8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c82ac: 0xc071fb4  jal         func_1C7ED0
    ctx->pc = 0x1C82ACu;
    SET_GPR_U32(ctx, 31, 0x1C82B4u);
    ctx->pc = 0x1C82B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C82ACu;
            // 0x1c82b0: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7ED0u;
    if (runtime->hasFunction(0x1C7ED0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C82B4u; }
        if (ctx->pc != 0x1C82B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7ED0_0x1c7ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C82B4u; }
        if (ctx->pc != 0x1C82B4u) { return; }
    }
    ctx->pc = 0x1C82B4u;
label_1c82b4:
    // 0x1c82b4: 0xc072044  jal         func_1C8110
    ctx->pc = 0x1C82B4u;
    SET_GPR_U32(ctx, 31, 0x1C82BCu);
    ctx->pc = 0x1C8110u;
    goto label_1c8110;
    ctx->pc = 0x1C82BCu;
label_1c82bc:
    // 0x1c82bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c82bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c82c0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c82c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c82c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C82C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C82C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C82C4u;
            // 0x1c82c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8110u: goto label_1c8110;
            case 0x1C8120u: goto label_1c8120;
            case 0x1C8140u: goto label_1c8140;
            case 0x1C8148u: goto label_1c8148;
            case 0x1C8178u: goto label_1c8178;
            case 0x1C8184u: goto label_1c8184;
            case 0x1C81FCu: goto label_1c81fc;
            case 0x1C823Cu: goto label_1c823c;
            case 0x1C8258u: goto label_1c8258;
            case 0x1C8278u: goto label_1c8278;
            case 0x1C8298u: goto label_1c8298;
            case 0x1C82B4u: goto label_1c82b4;
            case 0x1C82BCu: goto label_1c82bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C82CCu;
    // 0x1c82cc: 0x0  nop
    ctx->pc = 0x1c82ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
