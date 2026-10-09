#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019F430
// Address: 0x19f430 - 0x19f550
void sub_0019F430_0x19f430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019F430_0x19f430");
#endif

    switch (ctx->pc) {
        case 0x19f44cu: goto label_19f44c;
        case 0x19f454u: goto label_19f454;
        case 0x19f460u: goto label_19f460;
        case 0x19f48cu: goto label_19f48c;
        case 0x19f4a4u: goto label_19f4a4;
        case 0x19f4c0u: goto label_19f4c0;
        default: break;
    }

    ctx->pc = 0x19f430u;

    // 0x19f430: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x19f430u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x19f434: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x19f434u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x19f438: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x19f438u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x19f43c: 0x2484f9b0  addiu       $a0, $a0, -0x650
    ctx->pc = 0x19f43cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965680));
    // 0x19f440: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x19f440u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f444: 0xc0636e0  jal         func_18DB80
    ctx->pc = 0x19F444u;
    SET_GPR_U32(ctx, 31, 0x19F44Cu);
    ctx->pc = 0x19F448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F444u;
            // 0x19f448: 0x24060470  addiu       $a2, $zero, 0x470 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DB80u;
    if (runtime->hasFunction(0x18DB80u)) {
        auto targetFn = runtime->lookupFunction(0x18DB80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F44Cu; }
        if (ctx->pc != 0x19F44Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DB80_0x18db80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F44Cu; }
        if (ctx->pc != 0x19F44Cu) { return; }
    }
    ctx->pc = 0x19F44Cu;
label_19f44c:
    // 0x19f44c: 0xc067a98  jal         func_19EA60
    ctx->pc = 0x19F44Cu;
    SET_GPR_U32(ctx, 31, 0x19F454u);
    ctx->pc = 0x19EA60u;
    if (runtime->hasFunction(0x19EA60u)) {
        auto targetFn = runtime->lookupFunction(0x19EA60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F454u; }
        if (ctx->pc != 0x19F454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EA60_0x19ea60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F454u; }
        if (ctx->pc != 0x19F454u) { return; }
    }
    ctx->pc = 0x19F454u;
label_19f454:
    // 0x19f454: 0x3c020160  lui         $v0, 0x160
    ctx->pc = 0x19f454u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)352 << 16));
    // 0x19f458: 0xc041bb8  jal         func_106EE0
    ctx->pc = 0x19F458u;
    SET_GPR_U32(ctx, 31, 0x19F460u);
    ctx->pc = 0x19F45Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F458u;
            // 0x19f45c: 0x3444003f  ori         $a0, $v0, 0x3F (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)63);
        ctx->in_delay_slot = false;
    ctx->pc = 0x106EE0u;
    if (runtime->hasFunction(0x106EE0u)) {
        auto targetFn = runtime->lookupFunction(0x106EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F460u; }
        if (ctx->pc != 0x19F460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106EE0_0x106ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F460u; }
        if (ctx->pc != 0x19F460u) { return; }
    }
    ctx->pc = 0x19F460u;
label_19f460:
    // 0x19f460: 0x2443003f  addiu       $v1, $v0, 0x3F
    ctx->pc = 0x19f460u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 63));
    // 0x19f464: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x19f464u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x19f468: 0x622824  and         $a1, $v1, $v0
    ctx->pc = 0x19f468u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x19f46c: 0x14a00003  bnez        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19F46Cu;
    {
        const bool branch_taken_0x19f46c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F46Cu;
            // 0x19f470: 0x3c04002a  lui         $a0, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f46c) {
            ctx->pc = 0x19F47Cu;
            goto label_19f47c;
        }
    }
    ctx->pc = 0x19F474u;
    // 0x19f474: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x19F474u;
    {
        const bool branch_taken_0x19f474 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F474u;
            // 0x19f478: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f474) {
            ctx->pc = 0x19F540u;
            goto label_19f540;
        }
    }
    ctx->pc = 0x19F47Cu;
label_19f47c:
    // 0x19f47c: 0x3c060160  lui         $a2, 0x160
    ctx->pc = 0x19f47cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)352 << 16));
    // 0x19f480: 0x2484fe50  addiu       $a0, $a0, -0x1B0
    ctx->pc = 0x19f480u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966864));
    // 0x19f484: 0xc06265c  jal         func_189970
    ctx->pc = 0x19F484u;
    SET_GPR_U32(ctx, 31, 0x19F48Cu);
    ctx->pc = 0x19F488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F484u;
            // 0x19f488: 0x24070040  addiu       $a3, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189970u;
    if (runtime->hasFunction(0x189970u)) {
        auto targetFn = runtime->lookupFunction(0x189970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F48Cu; }
        if (ctx->pc != 0x19F48Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189970_0x189970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F48Cu; }
        if (ctx->pc != 0x19F48Cu) { return; }
    }
    ctx->pc = 0x19F48Cu;
label_19f48c:
    // 0x19f48c: 0x3c0200e0  lui         $v0, 0xE0
    ctx->pc = 0x19f48cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)224 << 16));
    // 0x19f490: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f490u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f494: 0xac22fdac  sw          $v0, -0x254($at)
    ctx->pc = 0x19f494u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966700), GPR_U32(ctx, 2));
    // 0x19f498: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f498u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f49c: 0xc06370c  jal         func_18DC30
    ctx->pc = 0x19F49Cu;
    SET_GPR_U32(ctx, 31, 0x19F4A4u);
    ctx->pc = 0x19F4A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F49Cu;
            // 0x19f4a0: 0x8c24fdac  lw          $a0, -0x254($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966700)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DC30u;
    if (runtime->hasFunction(0x18DC30u)) {
        auto targetFn = runtime->lookupFunction(0x18DC30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F4A4u; }
        if (ctx->pc != 0x19F4A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC30_0x18dc30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F4A4u; }
        if (ctx->pc != 0x19F4A4u) { return; }
    }
    ctx->pc = 0x19F4A4u;
label_19f4a4:
    // 0x19f4a4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f4a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f4a8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x19f4a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f4ac: 0xac22fda8  sw          $v0, -0x258($at)
    ctx->pc = 0x19f4acu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966696), GPR_U32(ctx, 2));
    // 0x19f4b0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f4b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f4b4: 0x8c25fdac  lw          $a1, -0x254($at)
    ctx->pc = 0x19f4b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966700)));
    // 0x19f4b8: 0xc068344  jal         func_1A0D10
    ctx->pc = 0x19F4B8u;
    SET_GPR_U32(ctx, 31, 0x19F4C0u);
    ctx->pc = 0x19F4BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F4B8u;
            // 0x19f4bc: 0x24060040  addiu       $a2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0D10u;
    if (runtime->hasFunction(0x1A0D10u)) {
        auto targetFn = runtime->lookupFunction(0x1A0D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F4C0u; }
        if (ctx->pc != 0x19F4C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0D10_0x1a0d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F4C0u; }
        if (ctx->pc != 0x19F4C0u) { return; }
    }
    ctx->pc = 0x19F4C0u;
label_19f4c0:
    // 0x19f4c0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f4c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f4c4: 0x3c020019  lui         $v0, 0x19
    ctx->pc = 0x19f4c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)25 << 16));
    // 0x19f4c8: 0xac20fda0  sw          $zero, -0x260($at)
    ctx->pc = 0x19f4c8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966688), GPR_U32(ctx, 0));
    // 0x19f4cc: 0x2442dbe0  addiu       $v0, $v0, -0x2420
    ctx->pc = 0x19f4ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958048));
    // 0x19f4d0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x19f4d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x19f4d4: 0xac22fff8  sw          $v0, -0x8($at)
    ctx->pc = 0x19f4d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967288), GPR_U32(ctx, 2));
    // 0x19f4d8: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x19f4d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x19f4dc: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x19f4dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x19f4e0: 0x24426f38  addiu       $v0, $v0, 0x6F38
    ctx->pc = 0x19f4e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 28472));
    // 0x19f4e4: 0xac22fff0  sw          $v0, -0x10($at)
    ctx->pc = 0x19f4e4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967280), GPR_U32(ctx, 2));
    // 0x19f4e8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x19f4e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x19f4ec: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f4ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f4f0: 0xac22fe78  sw          $v0, -0x188($at)
    ctx->pc = 0x19f4f0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966904), GPR_U32(ctx, 2));
    // 0x19f4f4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x19f4f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x19f4f8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f4f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f4fc: 0xac22fd9c  sw          $v0, -0x264($at)
    ctx->pc = 0x19f4fcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966684), GPR_U32(ctx, 2));
    // 0x19f500: 0x24020202  addiu       $v0, $zero, 0x202
    ctx->pc = 0x19f500u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 514));
    // 0x19f504: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f504u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f508: 0xac22fe70  sw          $v0, -0x190($at)
    ctx->pc = 0x19f508u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
    // 0x19f50c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f50cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f510: 0x3c020138  lui         $v0, 0x138
    ctx->pc = 0x19f510u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)312 << 16));
    // 0x19f514: 0xac20fee0  sw          $zero, -0x120($at)
    ctx->pc = 0x19f514u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967008), GPR_U32(ctx, 0));
    // 0x19f518: 0x3442b032  ori         $v0, $v0, 0xB032
    ctx->pc = 0x19f518u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)45106);
    // 0x19f51c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f51cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f520: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x19f520u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x19f524: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f524u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f528: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19f528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f52c: 0xac20bec0  sw          $zero, -0x4140($at)
    ctx->pc = 0x19f52cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294950592), GPR_U32(ctx, 0));
    // 0x19f530: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19f530u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19f534: 0xac204198  sw          $zero, 0x4198($at)
    ctx->pc = 0x19f534u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16792), GPR_U32(ctx, 0));
    // 0x19f538: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19f538u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19f53c: 0xac204178  sw          $zero, 0x4178($at)
    ctx->pc = 0x19f53cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16760), GPR_U32(ctx, 0));
label_19f540:
    // 0x19f540: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19f540u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19f544: 0x3e00008  jr          $ra
    ctx->pc = 0x19F544u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19F548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F544u;
            // 0x19f548: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19F44Cu: goto label_19f44c;
            case 0x19F454u: goto label_19f454;
            case 0x19F460u: goto label_19f460;
            case 0x19F47Cu: goto label_19f47c;
            case 0x19F48Cu: goto label_19f48c;
            case 0x19F4A4u: goto label_19f4a4;
            case 0x19F4C0u: goto label_19f4c0;
            case 0x19F540u: goto label_19f540;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19F54Cu;
    // 0x19f54c: 0x0  nop
    ctx->pc = 0x19f54cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
