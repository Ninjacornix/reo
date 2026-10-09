#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133490
// Address: 0x133490 - 0x133b48
void sub_00133490_0x133490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133490_0x133490");
#endif

    switch (ctx->pc) {
        case 0x1334c0u: goto label_1334c0;
        case 0x1334d0u: goto label_1334d0;
        case 0x1334ecu: goto label_1334ec;
        case 0x133514u: goto label_133514;
        case 0x133524u: goto label_133524;
        case 0x1335c8u: goto label_1335c8;
        case 0x1335d4u: goto label_1335d4;
        case 0x133690u: goto label_133690;
        case 0x133698u: goto label_133698;
        case 0x1336a4u: goto label_1336a4;
        case 0x1336b8u: goto label_1336b8;
        case 0x1336e0u: goto label_1336e0;
        case 0x133770u: goto label_133770;
        case 0x1337b4u: goto label_1337b4;
        case 0x1337f0u: goto label_1337f0;
        case 0x133804u: goto label_133804;
        case 0x133830u: goto label_133830;
        case 0x13389cu: goto label_13389c;
        case 0x1338a8u: goto label_1338a8;
        case 0x1338b4u: goto label_1338b4;
        case 0x1338c0u: goto label_1338c0;
        case 0x1338d0u: goto label_1338d0;
        case 0x1338e0u: goto label_1338e0;
        case 0x1338ecu: goto label_1338ec;
        case 0x1338f8u: goto label_1338f8;
        case 0x13395cu: goto label_13395c;
        case 0x133968u: goto label_133968;
        case 0x133974u: goto label_133974;
        case 0x1339a4u: goto label_1339a4;
        case 0x1339c0u: goto label_1339c0;
        case 0x1339e0u: goto label_1339e0;
        case 0x1339f8u: goto label_1339f8;
        case 0x133a04u: goto label_133a04;
        case 0x133a14u: goto label_133a14;
        case 0x133a20u: goto label_133a20;
        case 0x133a2cu: goto label_133a2c;
        case 0x133a4cu: goto label_133a4c;
        case 0x133a68u: goto label_133a68;
        case 0x133a80u: goto label_133a80;
        case 0x133a88u: goto label_133a88;
        case 0x133ae8u: goto label_133ae8;
        case 0x133b10u: goto label_133b10;
        case 0x133b20u: goto label_133b20;
        case 0x133b30u: goto label_133b30;
        default: break;
    }

    ctx->pc = 0x133490u;

    // 0x133490: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x133490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x133494: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x133494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x133498: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x133498u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13349c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x13349cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x1334a0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1334a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1334a4: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1334a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1334a8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1334a8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1334ac: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1334ACu;
    {
        const bool branch_taken_0x1334ac = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1334B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1334ACu;
            // 0x1334b0: 0xffbf0038  sd          $ra, 0x38($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1334ac) {
            ctx->pc = 0x1334C8u;
            goto label_1334c8;
        }
    }
    ctx->pc = 0x1334B4u;
    // 0x1334b4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1334b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1334b8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1334B8u;
    SET_GPR_U32(ctx, 31, 0x1334C0u);
    ctx->pc = 0x1334BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1334B8u;
            // 0x1334bc: 0x2484b578  addiu       $a0, $a0, -0x4A88 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1334C0u; }
        if (ctx->pc != 0x1334C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1334C0u; }
        if (ctx->pc != 0x1334C0u) { return; }
    }
    ctx->pc = 0x1334C0u;
label_1334c0:
    // 0x1334c0: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1334C0u;
    {
        const bool branch_taken_0x1334c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1334C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1334C0u;
            // 0x1334c4: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1334c0) {
            ctx->pc = 0x13356Cu;
            goto label_13356c;
        }
    }
    ctx->pc = 0x1334C8u;
label_1334c8:
    // 0x1334c8: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x1334C8u;
    SET_GPR_U32(ctx, 31, 0x1334D0u);
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1334D0u; }
        if (ctx->pc != 0x1334D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1334D0u; }
        if (ctx->pc != 0x1334D0u) { return; }
    }
    ctx->pc = 0x1334D0u;
label_1334d0:
    // 0x1334d0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1334d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1334d4: 0x8e0600b0  lw          $a2, 0xB0($s0)
    ctx->pc = 0x1334d4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 176)));
    // 0x1334d8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1334d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1334dc: 0x27a70010  addiu       $a3, $sp, 0x10
    ctx->pc = 0x1334dcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1334e0: 0x27a80014  addiu       $t0, $sp, 0x14
    ctx->pc = 0x1334e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    // 0x1334e4: 0xc04a786  jal         func_129E18
    ctx->pc = 0x1334E4u;
    SET_GPR_U32(ctx, 31, 0x1334ECu);
    ctx->pc = 0x1334E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1334E4u;
            // 0x1334e8: 0x27a90018  addiu       $t1, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129E18u;
    if (runtime->hasFunction(0x129E18u)) {
        auto targetFn = runtime->lookupFunction(0x129E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1334ECu; }
        if (ctx->pc != 0x1334ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129E18_0x129e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1334ECu; }
        if (ctx->pc != 0x1334ECu) { return; }
    }
    ctx->pc = 0x1334ECu;
label_1334ec:
    // 0x1334ec: 0x5440001f  bnel        $v0, $zero, . + 4 + (0x1F << 2)
    ctx->pc = 0x1334ECu;
    {
        const bool branch_taken_0x1334ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1334ec) {
            ctx->pc = 0x1334F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1334ECu;
            // 0x1334f0: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13356Cu;
            goto label_13356c;
        }
    }
    ctx->pc = 0x1334F4u;
    // 0x1334f4: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1334f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1334f8: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1334F8u;
    {
        const bool branch_taken_0x1334f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1334FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1334F8u;
            // 0x1334fc: 0x8fa30010  lw          $v1, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1334f8) {
            ctx->pc = 0x133538u;
            goto label_133538;
        }
    }
    ctx->pc = 0x133500u;
    // 0x133500: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133500u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133504: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x133504u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133508: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x133508u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13350c: 0xc04a0a8  jal         func_1282A0
    ctx->pc = 0x13350Cu;
    SET_GPR_U32(ctx, 31, 0x133514u);
    ctx->pc = 0x133510u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13350Cu;
            // 0x133510: 0x24070010  addiu       $a3, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1282A0u;
    if (runtime->hasFunction(0x1282A0u)) {
        auto targetFn = runtime->lookupFunction(0x1282A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133514u; }
        if (ctx->pc != 0x133514u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001282A0_0x1282a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133514u; }
        if (ctx->pc != 0x133514u) { return; }
    }
    ctx->pc = 0x133514u;
label_133514:
    // 0x133514: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x133514u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x133518: 0x2484b5a8  addiu       $a0, $a0, -0x4A58
    ctx->pc = 0x133518u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948264));
    // 0x13351c: 0xc04a04a  jal         func_128128
    ctx->pc = 0x13351Cu;
    SET_GPR_U32(ctx, 31, 0x133524u);
    ctx->pc = 0x133520u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13351Cu;
            // 0x133520: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128128u;
    if (runtime->hasFunction(0x128128u)) {
        auto targetFn = runtime->lookupFunction(0x128128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133524u; }
        if (ctx->pc != 0x133524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128128_0x128128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133524u; }
        if (ctx->pc != 0x133524u) { return; }
    }
    ctx->pc = 0x133524u;
label_133524:
    // 0x133524: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x133524u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x133528: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x133528u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x13352c: 0xa6020060  sh          $v0, 0x60($s0)
    ctx->pc = 0x13352cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 2));
    // 0x133530: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x133530u;
    {
        const bool branch_taken_0x133530 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x133534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133530u;
            // 0x133534: 0xa2030001  sb          $v1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133530) {
            ctx->pc = 0x133568u;
            goto label_133568;
        }
    }
    ctx->pc = 0x133538u;
label_133538:
    // 0x133538: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x133538u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13353c: 0x8fa40014  lw          $a0, 0x14($sp)
    ctx->pc = 0x13353cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x133540: 0x8fa50018  lw          $a1, 0x18($sp)
    ctx->pc = 0x133540u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x133544: 0x8e0600b0  lw          $a2, 0xB0($s0)
    ctx->pc = 0x133544u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 176)));
    // 0x133548: 0xae0300b8  sw          $v1, 0xB8($s0)
    ctx->pc = 0x133548u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 184), GPR_U32(ctx, 3));
    // 0x13354c: 0xae0600b4  sw          $a2, 0xB4($s0)
    ctx->pc = 0x13354cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 180), GPR_U32(ctx, 6));
    // 0x133550: 0xae0400bc  sw          $a0, 0xBC($s0)
    ctx->pc = 0x133550u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 188), GPR_U32(ctx, 4));
    // 0x133554: 0xae0500c0  sw          $a1, 0xC0($s0)
    ctx->pc = 0x133554u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 192), GPR_U32(ctx, 5));
    // 0x133558: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x133558u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x13355c: 0xa2000098  sb          $zero, 0x98($s0)
    ctx->pc = 0x13355cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 152), (uint8_t)GPR_U32(ctx, 0));
    // 0x133560: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x133560u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x133564: 0xa20200ac  sb          $v0, 0xAC($s0)
    ctx->pc = 0x133564u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 172), (uint8_t)GPR_U32(ctx, 2));
label_133568:
    // 0x133568: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x133568u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_13356c:
    // 0x13356c: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x13356cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x133570: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x133570u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x133574: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x133574u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x133578: 0x3e00008  jr          $ra
    ctx->pc = 0x133578u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13357Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133578u;
            // 0x13357c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1334C0u: goto label_1334c0;
            case 0x1334C8u: goto label_1334c8;
            case 0x1334D0u: goto label_1334d0;
            case 0x1334ECu: goto label_1334ec;
            case 0x133514u: goto label_133514;
            case 0x133524u: goto label_133524;
            case 0x133538u: goto label_133538;
            case 0x133568u: goto label_133568;
            case 0x13356Cu: goto label_13356c;
            case 0x1335A4u: goto label_1335a4;
            case 0x1335C0u: goto label_1335c0;
            case 0x1335C8u: goto label_1335c8;
            case 0x1335D4u: goto label_1335d4;
            case 0x133630u: goto label_133630;
            case 0x133664u: goto label_133664;
            case 0x133668u: goto label_133668;
            case 0x133688u: goto label_133688;
            case 0x133690u: goto label_133690;
            case 0x133698u: goto label_133698;
            case 0x1336A4u: goto label_1336a4;
            case 0x1336B8u: goto label_1336b8;
            case 0x1336D8u: goto label_1336d8;
            case 0x1336E0u: goto label_1336e0;
            case 0x133740u: goto label_133740;
            case 0x133744u: goto label_133744;
            case 0x133768u: goto label_133768;
            case 0x133770u: goto label_133770;
            case 0x1337B4u: goto label_1337b4;
            case 0x1337F0u: goto label_1337f0;
            case 0x133804u: goto label_133804;
            case 0x133828u: goto label_133828;
            case 0x133830u: goto label_133830;
            case 0x133858u: goto label_133858;
            case 0x13389Cu: goto label_13389c;
            case 0x1338A8u: goto label_1338a8;
            case 0x1338B4u: goto label_1338b4;
            case 0x1338C0u: goto label_1338c0;
            case 0x1338D0u: goto label_1338d0;
            case 0x1338E0u: goto label_1338e0;
            case 0x1338ECu: goto label_1338ec;
            case 0x1338F8u: goto label_1338f8;
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            case 0x133AE8u: goto label_133ae8;
            case 0x133B10u: goto label_133b10;
            case 0x133B20u: goto label_133b20;
            case 0x133B28u: goto label_133b28;
            case 0x133B30u: goto label_133b30;
            case 0x133B34u: goto label_133b34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133580u;
    // 0x133580: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x133580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x133584: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x133584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x133588: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x133588u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13358c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13358cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x133590: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x133590u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133594: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x133594u;
    {
        const bool branch_taken_0x133594 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x133598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133594u;
            // 0x133598: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133594) {
            ctx->pc = 0x1335A4u;
            goto label_1335a4;
        }
    }
    ctx->pc = 0x13359Cu;
    // 0x13359c: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x13359Cu;
    {
        const bool branch_taken_0x13359c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x13359c) {
            ctx->pc = 0x1335C0u;
            goto label_1335c0;
        }
    }
    ctx->pc = 0x1335A4u;
label_1335a4:
    // 0x1335a4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1335a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1335a8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1335a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1335ac: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1335acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1335b0: 0x2484b5d0  addiu       $a0, $a0, -0x4A30
    ctx->pc = 0x1335b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948304));
    // 0x1335b4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1335b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1335b8: 0x804a034  j           func_1280D0
    ctx->pc = 0x1335B8u;
    ctx->pc = 0x1335BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1335B8u;
            // 0x1335bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1335C0u;
label_1335c0:
    // 0x1335c0: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x1335C0u;
    SET_GPR_U32(ctx, 31, 0x1335C8u);
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1335C8u; }
        if (ctx->pc != 0x1335C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1335C8u; }
        if (ctx->pc != 0x1335C8u) { return; }
    }
    ctx->pc = 0x1335C8u;
label_1335c8:
    // 0x1335c8: 0x8e0400b0  lw          $a0, 0xB0($s0)
    ctx->pc = 0x1335c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 176)));
    // 0x1335cc: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1335CCu;
    SET_GPR_U32(ctx, 31, 0x1335D4u);
    ctx->pc = 0x1335D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1335CCu;
            // 0x1335d0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1335D4u; }
        if (ctx->pc != 0x1335D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1335D4u; }
        if (ctx->pc != 0x1335D4u) { return; }
    }
    ctx->pc = 0x1335D4u;
label_1335d4:
    // 0x1335d4: 0x8e0300b0  lw          $v1, 0xB0($s0)
    ctx->pc = 0x1335d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 176)));
    // 0x1335d8: 0x3c02000f  lui         $v0, 0xF
    ctx->pc = 0x1335d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
    // 0x1335dc: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1335dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1335e0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1335e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1335e4: 0xae0300b4  sw          $v1, 0xB4($s0)
    ctx->pc = 0x1335e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 180), GPR_U32(ctx, 3));
    // 0x1335e8: 0xae0200c0  sw          $v0, 0xC0($s0)
    ctx->pc = 0x1335e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 192), GPR_U32(ctx, 2));
    // 0x1335ec: 0xa20400ac  sb          $a0, 0xAC($s0)
    ctx->pc = 0x1335ecu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 172), (uint8_t)GPR_U32(ctx, 4));
    // 0x1335f0: 0xa2000098  sb          $zero, 0x98($s0)
    ctx->pc = 0x1335f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 152), (uint8_t)GPR_U32(ctx, 0));
    // 0x1335f4: 0xae0000b8  sw          $zero, 0xB8($s0)
    ctx->pc = 0x1335f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 184), GPR_U32(ctx, 0));
    // 0x1335f8: 0xae0000bc  sw          $zero, 0xBC($s0)
    ctx->pc = 0x1335f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 188), GPR_U32(ctx, 0));
    // 0x1335fc: 0xa2040001  sb          $a0, 0x1($s0)
    ctx->pc = 0x1335fcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x133600: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x133600u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x133604: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133604u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133608: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x133608u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13360c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13360cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133610: 0x3e00008  jr          $ra
    ctx->pc = 0x133610u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x133614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133610u;
            // 0x133614: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1334C0u: goto label_1334c0;
            case 0x1334C8u: goto label_1334c8;
            case 0x1334D0u: goto label_1334d0;
            case 0x1334ECu: goto label_1334ec;
            case 0x133514u: goto label_133514;
            case 0x133524u: goto label_133524;
            case 0x133538u: goto label_133538;
            case 0x133568u: goto label_133568;
            case 0x13356Cu: goto label_13356c;
            case 0x1335A4u: goto label_1335a4;
            case 0x1335C0u: goto label_1335c0;
            case 0x1335C8u: goto label_1335c8;
            case 0x1335D4u: goto label_1335d4;
            case 0x133630u: goto label_133630;
            case 0x133664u: goto label_133664;
            case 0x133668u: goto label_133668;
            case 0x133688u: goto label_133688;
            case 0x133690u: goto label_133690;
            case 0x133698u: goto label_133698;
            case 0x1336A4u: goto label_1336a4;
            case 0x1336B8u: goto label_1336b8;
            case 0x1336D8u: goto label_1336d8;
            case 0x1336E0u: goto label_1336e0;
            case 0x133740u: goto label_133740;
            case 0x133744u: goto label_133744;
            case 0x133768u: goto label_133768;
            case 0x133770u: goto label_133770;
            case 0x1337B4u: goto label_1337b4;
            case 0x1337F0u: goto label_1337f0;
            case 0x133804u: goto label_133804;
            case 0x133828u: goto label_133828;
            case 0x133830u: goto label_133830;
            case 0x133858u: goto label_133858;
            case 0x13389Cu: goto label_13389c;
            case 0x1338A8u: goto label_1338a8;
            case 0x1338B4u: goto label_1338b4;
            case 0x1338C0u: goto label_1338c0;
            case 0x1338D0u: goto label_1338d0;
            case 0x1338E0u: goto label_1338e0;
            case 0x1338ECu: goto label_1338ec;
            case 0x1338F8u: goto label_1338f8;
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            case 0x133AE8u: goto label_133ae8;
            case 0x133B10u: goto label_133b10;
            case 0x133B20u: goto label_133b20;
            case 0x133B28u: goto label_133b28;
            case 0x133B30u: goto label_133b30;
            case 0x133B34u: goto label_133b34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133618u;
    // 0x133618: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x133618u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13361c: 0x3c064000  lui         $a2, 0x4000
    ctx->pc = 0x13361cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)16384 << 16));
    // 0x133620: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x133620u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x133624: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x133624u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133628: 0x804cd8c  j           func_133630
    ctx->pc = 0x133628u;
    ctx->pc = 0x13362Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133628u;
            // 0x13362c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133630u;
    goto label_133630;
    ctx->pc = 0x133630u;
label_133630:
    // 0x133630: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x133630u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x133634: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x133634u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x133638: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x133638u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13363c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13363cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x133640: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x133640u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133644: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x133644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x133648: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x133648u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13364c: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13364Cu;
    {
        const bool branch_taken_0x13364c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x133650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13364Cu;
            // 0x133650: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13364c) {
            ctx->pc = 0x133664u;
            goto label_133664;
        }
    }
    ctx->pc = 0x133654u;
    // 0x133654: 0x52200004  beql        $s1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x133654u;
    {
        const bool branch_taken_0x133654 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x133654) {
            ctx->pc = 0x133658u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x133654u;
            // 0x133658: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x133668u;
            goto label_133668;
        }
    }
    ctx->pc = 0x13365Cu;
    // 0x13365c: 0x641000a  bgez        $s2, . + 4 + (0xA << 2)
    ctx->pc = 0x13365Cu;
    {
        const bool branch_taken_0x13365c = (GPR_S64(ctx, 18) >= 0);
        if (branch_taken_0x13365c) {
            ctx->pc = 0x133688u;
            goto label_133688;
        }
    }
    ctx->pc = 0x133664u;
label_133664:
    // 0x133664: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x133664u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
label_133668:
    // 0x133668: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x133668u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13366c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13366cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133670: 0x2484b600  addiu       $a0, $a0, -0x4A00
    ctx->pc = 0x133670u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948352));
    // 0x133674: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x133674u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133678: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x133678u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13367c: 0x804a034  j           func_1280D0
    ctx->pc = 0x13367Cu;
    ctx->pc = 0x133680u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13367Cu;
            // 0x133680: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133684u;
    // 0x133684: 0x0  nop
    ctx->pc = 0x133684u;
    // NOP
label_133688:
    // 0x133688: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x133688u;
    SET_GPR_U32(ctx, 31, 0x133690u);
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133690u; }
        if (ctx->pc != 0x133690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133690u; }
        if (ctx->pc != 0x133690u) { return; }
    }
    ctx->pc = 0x133690u;
label_133690:
    // 0x133690: 0xc049938  jal         func_1264E0
    ctx->pc = 0x133690u;
    SET_GPR_U32(ctx, 31, 0x133698u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133698u; }
        if (ctx->pc != 0x133698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133698u; }
        if (ctx->pc != 0x133698u) { return; }
    }
    ctx->pc = 0x133698u;
label_133698:
    // 0x133698: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133698u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13369c: 0xc04fcd8  jal         func_13F360
    ctx->pc = 0x13369Cu;
    SET_GPR_U32(ctx, 31, 0x1336A4u);
    ctx->pc = 0x1336A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13369Cu;
            // 0x1336a0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F360u;
    if (runtime->hasFunction(0x13F360u)) {
        auto targetFn = runtime->lookupFunction(0x13F360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336A4u; }
        if (ctx->pc != 0x1336A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F360_0x13f360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336A4u; }
        if (ctx->pc != 0x1336A4u) { return; }
    }
    ctx->pc = 0x1336A4u;
label_1336a4:
    // 0x1336a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1336a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1336a8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1336A8u;
    {
        const bool branch_taken_0x1336a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1336ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1336A8u;
            // 0x1336ac: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1336a8) {
            ctx->pc = 0x1336D8u;
            goto label_1336d8;
        }
    }
    ctx->pc = 0x1336B0u;
    // 0x1336b0: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x1336B0u;
    SET_GPR_U32(ctx, 31, 0x1336B8u);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336B8u; }
        if (ctx->pc != 0x1336B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336B8u; }
        if (ctx->pc != 0x1336B8u) { return; }
    }
    ctx->pc = 0x1336B8u;
label_1336b8:
    // 0x1336b8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1336b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1336bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1336bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1336c0: 0x2484b630  addiu       $a0, $a0, -0x49D0
    ctx->pc = 0x1336c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948400));
    // 0x1336c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1336c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1336c8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1336c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1336cc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1336ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1336d0: 0x804a034  j           func_1280D0
    ctx->pc = 0x1336D0u;
    ctx->pc = 0x1336D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1336D0u;
            // 0x1336d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1336D8u;
label_1336d8:
    // 0x1336d8: 0xc04c6d8  jal         func_131B60
    ctx->pc = 0x1336D8u;
    SET_GPR_U32(ctx, 31, 0x1336E0u);
    ctx->pc = 0x131B60u;
    if (runtime->hasFunction(0x131B60u)) {
        auto targetFn = runtime->lookupFunction(0x131B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336E0u; }
        if (ctx->pc != 0x1336E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131B60_0x131b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336E0u; }
        if (ctx->pc != 0x1336E0u) { return; }
    }
    ctx->pc = 0x1336E0u;
label_1336e0:
    // 0x1336e0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1336e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1336e4: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1336e4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1336e8: 0xa2000098  sb          $zero, 0x98($s0)
    ctx->pc = 0x1336e8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 152), (uint8_t)GPR_U32(ctx, 0));
    // 0x1336ec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1336ecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1336f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1336f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1336f4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1336f4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1336f8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1336f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1336fc: 0x804993e  j           func_1264F8
    ctx->pc = 0x1336FCu;
    ctx->pc = 0x133700u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1336FCu;
            // 0x133700: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133704u;
    // 0x133704: 0x0  nop
    ctx->pc = 0x133704u;
    // NOP
    // 0x133708: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x133708u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13370c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13370cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x133710: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x133710u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133714: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x133714u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x133718: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x133718u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13371c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13371cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x133720: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x133720u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133724: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x133724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x133728: 0x12400005  beqz        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x133728u;
    {
        const bool branch_taken_0x133728 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x13372Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133728u;
            // 0x13372c: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133728) {
            ctx->pc = 0x133740u;
            goto label_133740;
        }
    }
    ctx->pc = 0x133730u;
    // 0x133730: 0x52200004  beql        $s1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x133730u;
    {
        const bool branch_taken_0x133730 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x133730) {
            ctx->pc = 0x133734u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x133730u;
            // 0x133734: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x133744u;
            goto label_133744;
        }
    }
    ctx->pc = 0x133738u;
    // 0x133738: 0x601000b  bgez        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x133738u;
    {
        const bool branch_taken_0x133738 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x133738) {
            ctx->pc = 0x133768u;
            goto label_133768;
        }
    }
    ctx->pc = 0x133740u;
label_133740:
    // 0x133740: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x133740u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
label_133744:
    // 0x133744: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x133744u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133748: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133748u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13374c: 0x2484b660  addiu       $a0, $a0, -0x49A0
    ctx->pc = 0x13374cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948448));
    // 0x133750: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x133750u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133754: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x133754u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x133758: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x133758u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13375c: 0x804a034  j           func_1280D0
    ctx->pc = 0x13375Cu;
    ctx->pc = 0x133760u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13375Cu;
            // 0x133760: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133764u;
    // 0x133764: 0x0  nop
    ctx->pc = 0x133764u;
    // NOP
label_133768:
    // 0x133768: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x133768u;
    SET_GPR_U32(ctx, 31, 0x133770u);
    ctx->pc = 0x13376Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133768u;
            // 0x13376c: 0x3c1300ff  lui         $s3, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)255 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133770u; }
        if (ctx->pc != 0x133770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133770u; }
        if (ctx->pc != 0x133770u) { return; }
    }
    ctx->pc = 0x133770u;
label_133770:
    // 0x133770: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x133770u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x133774: 0x32a03  sra         $a1, $v1, 8
    ctx->pc = 0x133774u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 3), 8));
    // 0x133778: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x133778u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x13377c: 0x31602  srl         $v0, $v1, 24
    ctx->pc = 0x13377cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 24));
    // 0x133780: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x133780u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x133784: 0x932024  and         $a0, $a0, $s3
    ctx->pc = 0x133784u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 19));
    // 0x133788: 0x30a5ff00  andi        $a1, $a1, 0xFF00
    ctx->pc = 0x133788u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x13378c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x13378cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x133790: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x133790u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x133794: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x133794u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x133798: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x133798u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13379c: 0x5040002e  beql        $v0, $zero, . + 4 + (0x2E << 2)
    ctx->pc = 0x13379Cu;
    {
        const bool branch_taken_0x13379c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13379c) {
            ctx->pc = 0x1337A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13379Cu;
            // 0x1337a0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x133858u;
            goto label_133858;
        }
    }
    ctx->pc = 0x1337A4u;
    // 0x1337a4: 0x602002c  bltzl       $s0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1337A4u;
    {
        const bool branch_taken_0x1337a4 = (GPR_S64(ctx, 16) < 0);
        if (branch_taken_0x1337a4) {
            ctx->pc = 0x1337A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1337A4u;
            // 0x1337a8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x133858u;
            goto label_133858;
        }
    }
    ctx->pc = 0x1337ACu;
    // 0x1337ac: 0xc049938  jal         func_1264E0
    ctx->pc = 0x1337ACu;
    SET_GPR_U32(ctx, 31, 0x1337B4u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1337B4u; }
        if (ctx->pc != 0x1337B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1337B4u; }
        if (ctx->pc != 0x1337B4u) { return; }
    }
    ctx->pc = 0x1337B4u;
label_1337b4:
    // 0x1337b4: 0x3c054000  lui         $a1, 0x4000
    ctx->pc = 0x1337b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16384 << 16));
    // 0x1337b8: 0x1010c0  sll         $v0, $s0, 3
    ctx->pc = 0x1337b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1337bc: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1337bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1337c0: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1337c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1337c4: 0x33203  sra         $a2, $v1, 8
    ctx->pc = 0x1337c4u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 3), 8));
    // 0x1337c8: 0x31200  sll         $v0, $v1, 8
    ctx->pc = 0x1337c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1337cc: 0x30c6ff00  andi        $a2, $a2, 0xFF00
    ctx->pc = 0x1337ccu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65280);
    // 0x1337d0: 0x32602  srl         $a0, $v1, 24
    ctx->pc = 0x1337d0u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 3), 24));
    // 0x1337d4: 0x531024  and         $v0, $v0, $s3
    ctx->pc = 0x1337d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 19));
    // 0x1337d8: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1337d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1337dc: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1337dcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1337e0: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x1337e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x1337e4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1337e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1337e8: 0xc04fcd8  jal         func_13F360
    ctx->pc = 0x1337E8u;
    SET_GPR_U32(ctx, 31, 0x1337F0u);
    ctx->pc = 0x1337ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1337E8u;
            // 0x1337ec: 0x2242021  addu        $a0, $s1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F360u;
    if (runtime->hasFunction(0x13F360u)) {
        auto targetFn = runtime->lookupFunction(0x13F360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1337F0u; }
        if (ctx->pc != 0x1337F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F360_0x13f360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1337F0u; }
        if (ctx->pc != 0x1337F0u) { return; }
    }
    ctx->pc = 0x1337F0u;
label_1337f0:
    // 0x1337f0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1337f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1337f4: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1337F4u;
    {
        const bool branch_taken_0x1337f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1337F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1337F4u;
            // 0x1337f8: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1337f4) {
            ctx->pc = 0x133828u;
            goto label_133828;
        }
    }
    ctx->pc = 0x1337FCu;
    // 0x1337fc: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x1337FCu;
    SET_GPR_U32(ctx, 31, 0x133804u);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133804u; }
        if (ctx->pc != 0x133804u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133804u; }
        if (ctx->pc != 0x133804u) { return; }
    }
    ctx->pc = 0x133804u;
label_133804:
    // 0x133804: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x133804u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x133808: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x133808u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13380c: 0x2484b690  addiu       $a0, $a0, -0x4970
    ctx->pc = 0x13380cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948496));
    // 0x133810: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133810u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133814: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x133814u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133818: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x133818u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13381c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13381cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x133820: 0x804a034  j           func_1280D0
    ctx->pc = 0x133820u;
    ctx->pc = 0x133824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133820u;
            // 0x133824: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133828u;
label_133828:
    // 0x133828: 0xc04c6d8  jal         func_131B60
    ctx->pc = 0x133828u;
    SET_GPR_U32(ctx, 31, 0x133830u);
    ctx->pc = 0x131B60u;
    if (runtime->hasFunction(0x131B60u)) {
        auto targetFn = runtime->lookupFunction(0x131B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133830u; }
        if (ctx->pc != 0x133830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131B60_0x131b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133830u; }
        if (ctx->pc != 0x133830u) { return; }
    }
    ctx->pc = 0x133830u;
label_133830:
    // 0x133830: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x133830u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x133834: 0xa2420002  sb          $v0, 0x2($s2)
    ctx->pc = 0x133834u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x133838: 0xa2400098  sb          $zero, 0x98($s2)
    ctx->pc = 0x133838u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 152), (uint8_t)GPR_U32(ctx, 0));
    // 0x13383c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13383cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133840: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133840u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133844: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x133844u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133848: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x133848u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13384c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13384cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x133850: 0x804993e  j           func_1264F8
    ctx->pc = 0x133850u;
    ctx->pc = 0x133854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133850u;
            // 0x133854: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133858u;
label_133858:
    // 0x133858: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133858u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13385c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13385cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133860: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x133860u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x133864: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x133864u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x133868: 0x3e00008  jr          $ra
    ctx->pc = 0x133868u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13386Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133868u;
            // 0x13386c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1334C0u: goto label_1334c0;
            case 0x1334C8u: goto label_1334c8;
            case 0x1334D0u: goto label_1334d0;
            case 0x1334ECu: goto label_1334ec;
            case 0x133514u: goto label_133514;
            case 0x133524u: goto label_133524;
            case 0x133538u: goto label_133538;
            case 0x133568u: goto label_133568;
            case 0x13356Cu: goto label_13356c;
            case 0x1335A4u: goto label_1335a4;
            case 0x1335C0u: goto label_1335c0;
            case 0x1335C8u: goto label_1335c8;
            case 0x1335D4u: goto label_1335d4;
            case 0x133630u: goto label_133630;
            case 0x133664u: goto label_133664;
            case 0x133668u: goto label_133668;
            case 0x133688u: goto label_133688;
            case 0x133690u: goto label_133690;
            case 0x133698u: goto label_133698;
            case 0x1336A4u: goto label_1336a4;
            case 0x1336B8u: goto label_1336b8;
            case 0x1336D8u: goto label_1336d8;
            case 0x1336E0u: goto label_1336e0;
            case 0x133740u: goto label_133740;
            case 0x133744u: goto label_133744;
            case 0x133768u: goto label_133768;
            case 0x133770u: goto label_133770;
            case 0x1337B4u: goto label_1337b4;
            case 0x1337F0u: goto label_1337f0;
            case 0x133804u: goto label_133804;
            case 0x133828u: goto label_133828;
            case 0x133830u: goto label_133830;
            case 0x133858u: goto label_133858;
            case 0x13389Cu: goto label_13389c;
            case 0x1338A8u: goto label_1338a8;
            case 0x1338B4u: goto label_1338b4;
            case 0x1338C0u: goto label_1338c0;
            case 0x1338D0u: goto label_1338d0;
            case 0x1338E0u: goto label_1338e0;
            case 0x1338ECu: goto label_1338ec;
            case 0x1338F8u: goto label_1338f8;
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            case 0x133AE8u: goto label_133ae8;
            case 0x133B10u: goto label_133b10;
            case 0x133B20u: goto label_133b20;
            case 0x133B28u: goto label_133b28;
            case 0x133B30u: goto label_133b30;
            case 0x133B34u: goto label_133b34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133870u;
    // 0x133870: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x133870u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x133874: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x133874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x133878: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x133878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13387c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x13387cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133880: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x133880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x133884: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x133884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x133888: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x133888u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x13388c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13388cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x133890: 0x8e510004  lw          $s1, 0x4($s2)
    ctx->pc = 0x133890u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x133894: 0xc04b61a  jal         func_12D868
    ctx->pc = 0x133894u;
    SET_GPR_U32(ctx, 31, 0x13389Cu);
    ctx->pc = 0x133898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133894u;
            // 0x133898: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D868u;
    if (runtime->hasFunction(0x12D868u)) {
        auto targetFn = runtime->lookupFunction(0x12D868u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13389Cu; }
        if (ctx->pc != 0x13389Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D868_0x12d868(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13389Cu; }
        if (ctx->pc != 0x13389Cu) { return; }
    }
    ctx->pc = 0x13389Cu;
label_13389c:
    // 0x13389c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13389cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338a0: 0xc04b620  jal         func_12D880
    ctx->pc = 0x1338A0u;
    SET_GPR_U32(ctx, 31, 0x1338A8u);
    ctx->pc = 0x1338A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338A0u;
            // 0x1338a4: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D880u;
    if (runtime->hasFunction(0x12D880u)) {
        auto targetFn = runtime->lookupFunction(0x12D880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338A8u; }
        if (ctx->pc != 0x1338A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D880_0x12d880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338A8u; }
        if (ctx->pc != 0x1338A8u) { return; }
    }
    ctx->pc = 0x1338A8u;
label_1338a8:
    // 0x1338a8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338ac: 0xc04b62c  jal         func_12D8B0
    ctx->pc = 0x1338ACu;
    SET_GPR_U32(ctx, 31, 0x1338B4u);
    ctx->pc = 0x1338B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338ACu;
            // 0x1338b0: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D8B0u;
    if (runtime->hasFunction(0x12D8B0u)) {
        auto targetFn = runtime->lookupFunction(0x12D8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338B4u; }
        if (ctx->pc != 0x1338B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D8B0_0x12d8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338B4u; }
        if (ctx->pc != 0x1338B4u) { return; }
    }
    ctx->pc = 0x1338B4u;
label_1338b4:
    // 0x1338b4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338b8: 0xc04b68e  jal         func_12DA38
    ctx->pc = 0x1338B8u;
    SET_GPR_U32(ctx, 31, 0x1338C0u);
    ctx->pc = 0x1338BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338B8u;
            // 0x1338bc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DA38u;
    if (runtime->hasFunction(0x12DA38u)) {
        auto targetFn = runtime->lookupFunction(0x12DA38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338C0u; }
        if (ctx->pc != 0x1338C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DA38_0x12da38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338C0u; }
        if (ctx->pc != 0x1338C0u) { return; }
    }
    ctx->pc = 0x1338C0u;
label_1338c0:
    // 0x1338c0: 0x2138023  subu        $s0, $s0, $s3
    ctx->pc = 0x1338c0u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x1338c4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338c8: 0xc04b5d6  jal         func_12D758
    ctx->pc = 0x1338C8u;
    SET_GPR_U32(ctx, 31, 0x1338D0u);
    ctx->pc = 0x1338CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338C8u;
            // 0x1338cc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D758u;
    if (runtime->hasFunction(0x12D758u)) {
        auto targetFn = runtime->lookupFunction(0x12D758u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338D0u; }
        if (ctx->pc != 0x1338D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D758_0x12d758(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338D0u; }
        if (ctx->pc != 0x1338D0u) { return; }
    }
    ctx->pc = 0x1338D0u;
label_1338d0:
    // 0x1338d0: 0xae500090  sw          $s0, 0x90($s2)
    ctx->pc = 0x1338d0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 144), GPR_U32(ctx, 16));
    // 0x1338d4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1338d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338d8: 0xc04b5d2  jal         func_12D748
    ctx->pc = 0x1338D8u;
    SET_GPR_U32(ctx, 31, 0x1338E0u);
    ctx->pc = 0x1338DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338D8u;
            // 0x1338dc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D748u;
    if (runtime->hasFunction(0x12D748u)) {
        auto targetFn = runtime->lookupFunction(0x12D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338E0u; }
        if (ctx->pc != 0x1338E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D748_0x12d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338E0u; }
        if (ctx->pc != 0x1338E0u) { return; }
    }
    ctx->pc = 0x1338E0u;
label_1338e0:
    // 0x1338e0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338e4: 0xc04b5da  jal         func_12D768
    ctx->pc = 0x1338E4u;
    SET_GPR_U32(ctx, 31, 0x1338ECu);
    ctx->pc = 0x1338E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338E4u;
            // 0x1338e8: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D768u;
    if (runtime->hasFunction(0x12D768u)) {
        auto targetFn = runtime->lookupFunction(0x12D768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338ECu; }
        if (ctx->pc != 0x1338ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D768_0x12d768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338ECu; }
        if (ctx->pc != 0x1338ECu) { return; }
    }
    ctx->pc = 0x1338ECu;
label_1338ec:
    // 0x1338ec: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338f0: 0xc04b5ba  jal         func_12D6E8
    ctx->pc = 0x1338F0u;
    SET_GPR_U32(ctx, 31, 0x1338F8u);
    ctx->pc = 0x1338F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338F0u;
            // 0x1338f4: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D6E8u;
    if (runtime->hasFunction(0x12D6E8u)) {
        auto targetFn = runtime->lookupFunction(0x12D6E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338F8u; }
        if (ctx->pc != 0x1338F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D6E8_0x12d6e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338F8u; }
        if (ctx->pc != 0x1338F8u) { return; }
    }
    ctx->pc = 0x1338F8u;
label_1338f8:
    // 0x1338f8: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x1338f8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x1338fc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133900: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133900u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133904: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x133904u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133908: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x133908u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13390c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13390cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133910: 0x24a53928  addiu       $a1, $a1, 0x3928
    ctx->pc = 0x133910u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 14632));
    // 0x133914: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x133914u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x133918: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x133918u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13391c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x13391cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x133920: 0x804b5ce  j           func_12D738
    ctx->pc = 0x133920u;
    ctx->pc = 0x133924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133920u;
            // 0x133924: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D738u;
    if (runtime->hasFunction(0x12D738u)) {
        auto targetFn = runtime->lookupFunction(0x12D738u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012D738_0x12d738(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133928u;
    // 0x133928: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x133928u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x13392c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13392cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x133930: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x133930u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133934: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x133934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x133938: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x133938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x13393c: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x13393cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x133940: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x133940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x133944: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x133944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x133948: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x133948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x13394c: 0x8e320004  lw          $s2, 0x4($s1)
    ctx->pc = 0x13394cu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x133950: 0x8e300014  lw          $s0, 0x14($s1)
    ctx->pc = 0x133950u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x133954: 0xc04b61a  jal         func_12D868
    ctx->pc = 0x133954u;
    SET_GPR_U32(ctx, 31, 0x13395Cu);
    ctx->pc = 0x133958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133954u;
            // 0x133958: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D868u;
    if (runtime->hasFunction(0x12D868u)) {
        auto targetFn = runtime->lookupFunction(0x12D868u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13395Cu; }
        if (ctx->pc != 0x13395Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D868_0x12d868(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13395Cu; }
        if (ctx->pc != 0x13395Cu) { return; }
    }
    ctx->pc = 0x13395Cu;
label_13395c:
    // 0x13395c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13395cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133960: 0xc04b620  jal         func_12D880
    ctx->pc = 0x133960u;
    SET_GPR_U32(ctx, 31, 0x133968u);
    ctx->pc = 0x133964u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133960u;
            // 0x133964: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D880u;
    if (runtime->hasFunction(0x12D880u)) {
        auto targetFn = runtime->lookupFunction(0x12D880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133968u; }
        if (ctx->pc != 0x133968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D880_0x12d880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133968u; }
        if (ctx->pc != 0x133968u) { return; }
    }
    ctx->pc = 0x133968u;
label_133968:
    // 0x133968: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x133968u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13396c: 0xc04b62c  jal         func_12D8B0
    ctx->pc = 0x13396Cu;
    SET_GPR_U32(ctx, 31, 0x133974u);
    ctx->pc = 0x133970u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13396Cu;
            // 0x133970: 0x40a82d  daddu       $s5, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D8B0u;
    if (runtime->hasFunction(0x12D8B0u)) {
        auto targetFn = runtime->lookupFunction(0x12D8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133974u; }
        if (ctx->pc != 0x133974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D8B0_0x12d8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133974u; }
        if (ctx->pc != 0x133974u) { return; }
    }
    ctx->pc = 0x133974u;
label_133974:
    // 0x133974: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x133974u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133978: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x133978u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13397c: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x13397cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x133980: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x133980u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x133984: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x133984u;
    {
        const bool branch_taken_0x133984 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x133988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133984u;
            // 0x133988: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133984) {
            ctx->pc = 0x1339B0u;
            goto label_1339b0;
        }
    }
    ctx->pc = 0x13398Cu;
    // 0x13398c: 0x8222006c  lb          $v0, 0x6C($s1)
    ctx->pc = 0x13398cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 108)));
    // 0x133990: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x133990u;
    {
        const bool branch_taken_0x133990 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x133990) {
            ctx->pc = 0x133994u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x133990u;
            // 0x133994: 0x8e030000  lw          $v1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1339B4u;
            goto label_1339b4;
        }
    }
    ctx->pc = 0x133998u;
    // 0x133998: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x133998u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13399c: 0xc04b5d2  jal         func_12D748
    ctx->pc = 0x13399Cu;
    SET_GPR_U32(ctx, 31, 0x1339A4u);
    ctx->pc = 0x1339A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13399Cu;
            // 0x1339a0: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D748u;
    if (runtime->hasFunction(0x12D748u)) {
        auto targetFn = runtime->lookupFunction(0x12D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1339A4u; }
        if (ctx->pc != 0x1339A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D748_0x12d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1339A4u; }
        if (ctx->pc != 0x1339A4u) { return; }
    }
    ctx->pc = 0x1339A4u;
label_1339a4:
    // 0x1339a4: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1339A4u;
    {
        const bool branch_taken_0x1339a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1339A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1339A4u;
            // 0x1339a8: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1339a4) {
            ctx->pc = 0x133A98u;
            goto label_133a98;
        }
    }
    ctx->pc = 0x1339ACu;
    // 0x1339ac: 0x0  nop
    ctx->pc = 0x1339acu;
    // NOP
label_1339b0:
    // 0x1339b0: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1339b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_1339b4:
    // 0x1339b4: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x1339b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1339b8: 0x40f809  jalr        $v0
    ctx->pc = 0x1339B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1339C0u);
        ctx->pc = 0x1339BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1339B8u;
            // 0x1339bc: 0x8e260050  lw          $a2, 0x50($s1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 80)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1339C0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1334C0u: goto label_1334c0;
            case 0x1334C8u: goto label_1334c8;
            case 0x1334D0u: goto label_1334d0;
            case 0x1334ECu: goto label_1334ec;
            case 0x133514u: goto label_133514;
            case 0x133524u: goto label_133524;
            case 0x133538u: goto label_133538;
            case 0x133568u: goto label_133568;
            case 0x13356Cu: goto label_13356c;
            case 0x1335A4u: goto label_1335a4;
            case 0x1335C0u: goto label_1335c0;
            case 0x1335C8u: goto label_1335c8;
            case 0x1335D4u: goto label_1335d4;
            case 0x133630u: goto label_133630;
            case 0x133664u: goto label_133664;
            case 0x133668u: goto label_133668;
            case 0x133688u: goto label_133688;
            case 0x133690u: goto label_133690;
            case 0x133698u: goto label_133698;
            case 0x1336A4u: goto label_1336a4;
            case 0x1336B8u: goto label_1336b8;
            case 0x1336D8u: goto label_1336d8;
            case 0x1336E0u: goto label_1336e0;
            case 0x133740u: goto label_133740;
            case 0x133744u: goto label_133744;
            case 0x133768u: goto label_133768;
            case 0x133770u: goto label_133770;
            case 0x1337B4u: goto label_1337b4;
            case 0x1337F0u: goto label_1337f0;
            case 0x133804u: goto label_133804;
            case 0x133828u: goto label_133828;
            case 0x133830u: goto label_133830;
            case 0x133858u: goto label_133858;
            case 0x13389Cu: goto label_13389c;
            case 0x1338A8u: goto label_1338a8;
            case 0x1338B4u: goto label_1338b4;
            case 0x1338C0u: goto label_1338c0;
            case 0x1338D0u: goto label_1338d0;
            case 0x1338E0u: goto label_1338e0;
            case 0x1338ECu: goto label_1338ec;
            case 0x1338F8u: goto label_1338f8;
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            case 0x133AE8u: goto label_133ae8;
            case 0x133B10u: goto label_133b10;
            case 0x133B20u: goto label_133b20;
            case 0x133B28u: goto label_133b28;
            case 0x133B30u: goto label_133b30;
            case 0x133B34u: goto label_133b34;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1339C0u; }
            if (ctx->pc != 0x1339C0u) { return; }
        }
        }
    }
    ctx->pc = 0x1339C0u;
label_1339c0:
    // 0x1339c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1339c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1339c4: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x1339c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1339c8: 0x8e230050  lw          $v1, 0x50($s1)
    ctx->pc = 0x1339c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 80)));
    // 0x1339cc: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1339ccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1339d0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1339D0u;
    {
        const bool branch_taken_0x1339d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1339D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1339D0u;
            // 0x1339d4: 0x2484b6c0  addiu       $a0, $a0, -0x4940 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948544));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1339d0) {
            ctx->pc = 0x1339E0u;
            goto label_1339e0;
        }
    }
    ctx->pc = 0x1339D8u;
    // 0x1339d8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1339D8u;
    SET_GPR_U32(ctx, 31, 0x1339E0u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1339E0u; }
        if (ctx->pc != 0x1339E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1339E0u; }
        if (ctx->pc != 0x1339E0u) { return; }
    }
    ctx->pc = 0x1339E0u;
label_1339e0:
    // 0x1339e0: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1339e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1339e4: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1339e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1339e8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1339e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1339ec: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x1339ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1339f0: 0x40f809  jalr        $v0
    ctx->pc = 0x1339F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1339F8u);
        ctx->pc = 0x1339F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1339F0u;
            // 0x1339f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1339F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1334C0u: goto label_1334c0;
            case 0x1334C8u: goto label_1334c8;
            case 0x1334D0u: goto label_1334d0;
            case 0x1334ECu: goto label_1334ec;
            case 0x133514u: goto label_133514;
            case 0x133524u: goto label_133524;
            case 0x133538u: goto label_133538;
            case 0x133568u: goto label_133568;
            case 0x13356Cu: goto label_13356c;
            case 0x1335A4u: goto label_1335a4;
            case 0x1335C0u: goto label_1335c0;
            case 0x1335C8u: goto label_1335c8;
            case 0x1335D4u: goto label_1335d4;
            case 0x133630u: goto label_133630;
            case 0x133664u: goto label_133664;
            case 0x133668u: goto label_133668;
            case 0x133688u: goto label_133688;
            case 0x133690u: goto label_133690;
            case 0x133698u: goto label_133698;
            case 0x1336A4u: goto label_1336a4;
            case 0x1336B8u: goto label_1336b8;
            case 0x1336D8u: goto label_1336d8;
            case 0x1336E0u: goto label_1336e0;
            case 0x133740u: goto label_133740;
            case 0x133744u: goto label_133744;
            case 0x133768u: goto label_133768;
            case 0x133770u: goto label_133770;
            case 0x1337B4u: goto label_1337b4;
            case 0x1337F0u: goto label_1337f0;
            case 0x133804u: goto label_133804;
            case 0x133828u: goto label_133828;
            case 0x133830u: goto label_133830;
            case 0x133858u: goto label_133858;
            case 0x13389Cu: goto label_13389c;
            case 0x1338A8u: goto label_1338a8;
            case 0x1338B4u: goto label_1338b4;
            case 0x1338C0u: goto label_1338c0;
            case 0x1338D0u: goto label_1338d0;
            case 0x1338E0u: goto label_1338e0;
            case 0x1338ECu: goto label_1338ec;
            case 0x1338F8u: goto label_1338f8;
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            case 0x133AE8u: goto label_133ae8;
            case 0x133B10u: goto label_133b10;
            case 0x133B20u: goto label_133b20;
            case 0x133B28u: goto label_133b28;
            case 0x133B30u: goto label_133b30;
            case 0x133B34u: goto label_133b34;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1339F8u; }
            if (ctx->pc != 0x1339F8u) { return; }
        }
        }
    }
    ctx->pc = 0x1339F8u;
label_1339f8:
    // 0x1339f8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1339f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1339fc: 0xc04b5d6  jal         func_12D758
    ctx->pc = 0x1339FCu;
    SET_GPR_U32(ctx, 31, 0x133A04u);
    ctx->pc = 0x133A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1339FCu;
            // 0x133a00: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D758u;
    if (runtime->hasFunction(0x12D758u)) {
        auto targetFn = runtime->lookupFunction(0x12D758u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A04u; }
        if (ctx->pc != 0x133A04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D758_0x12d758(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A04u; }
        if (ctx->pc != 0x133A04u) { return; }
    }
    ctx->pc = 0x133A04u;
label_133a04:
    // 0x133a04: 0x2932823  subu        $a1, $s4, $s3
    ctx->pc = 0x133a04u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 19)));
    // 0x133a08: 0xae250090  sw          $a1, 0x90($s1)
    ctx->pc = 0x133a08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 5));
    // 0x133a0c: 0xc04b5d2  jal         func_12D748
    ctx->pc = 0x133A0Cu;
    SET_GPR_U32(ctx, 31, 0x133A14u);
    ctx->pc = 0x133A10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133A0Cu;
            // 0x133a10: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D748u;
    if (runtime->hasFunction(0x12D748u)) {
        auto targetFn = runtime->lookupFunction(0x12D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A14u; }
        if (ctx->pc != 0x133A14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D748_0x12d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A14u; }
        if (ctx->pc != 0x133A14u) { return; }
    }
    ctx->pc = 0x133A14u;
label_133a14:
    // 0x133a14: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x133a14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a18: 0xc04b5da  jal         func_12D768
    ctx->pc = 0x133A18u;
    SET_GPR_U32(ctx, 31, 0x133A20u);
    ctx->pc = 0x133A1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133A18u;
            // 0x133a1c: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D768u;
    if (runtime->hasFunction(0x12D768u)) {
        auto targetFn = runtime->lookupFunction(0x12D768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A20u; }
        if (ctx->pc != 0x133A20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D768_0x12d768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A20u; }
        if (ctx->pc != 0x133A20u) { return; }
    }
    ctx->pc = 0x133A20u;
label_133a20:
    // 0x133a20: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x133a20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a24: 0xc04b5ba  jal         func_12D6E8
    ctx->pc = 0x133A24u;
    SET_GPR_U32(ctx, 31, 0x133A2Cu);
    ctx->pc = 0x133A28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133A24u;
            // 0x133a28: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D6E8u;
    if (runtime->hasFunction(0x12D6E8u)) {
        auto targetFn = runtime->lookupFunction(0x12D6E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A2Cu; }
        if (ctx->pc != 0x133A2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D6E8_0x12d6e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A2Cu; }
        if (ctx->pc != 0x133A2Cu) { return; }
    }
    ctx->pc = 0x133A2Cu;
label_133a2c:
    // 0x133a2c: 0x82230002  lb          $v1, 0x2($s1)
    ctx->pc = 0x133a2cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x133a30: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x133a30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x133a34: 0x14620012  bne         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x133A34u;
    {
        const bool branch_taken_0x133a34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x133A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133A34u;
            // 0x133a38: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133a34) {
            ctx->pc = 0x133A80u;
            goto label_133a80;
        }
    }
    ctx->pc = 0x133A3Cu;
    // 0x133a3c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x133a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x133a40: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x133a40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x133a44: 0x60f809  jalr        $v1
    ctx->pc = 0x133A44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x133A4Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x133A4Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1334C0u: goto label_1334c0;
            case 0x1334C8u: goto label_1334c8;
            case 0x1334D0u: goto label_1334d0;
            case 0x1334ECu: goto label_1334ec;
            case 0x133514u: goto label_133514;
            case 0x133524u: goto label_133524;
            case 0x133538u: goto label_133538;
            case 0x133568u: goto label_133568;
            case 0x13356Cu: goto label_13356c;
            case 0x1335A4u: goto label_1335a4;
            case 0x1335C0u: goto label_1335c0;
            case 0x1335C8u: goto label_1335c8;
            case 0x1335D4u: goto label_1335d4;
            case 0x133630u: goto label_133630;
            case 0x133664u: goto label_133664;
            case 0x133668u: goto label_133668;
            case 0x133688u: goto label_133688;
            case 0x133690u: goto label_133690;
            case 0x133698u: goto label_133698;
            case 0x1336A4u: goto label_1336a4;
            case 0x1336B8u: goto label_1336b8;
            case 0x1336D8u: goto label_1336d8;
            case 0x1336E0u: goto label_1336e0;
            case 0x133740u: goto label_133740;
            case 0x133744u: goto label_133744;
            case 0x133768u: goto label_133768;
            case 0x133770u: goto label_133770;
            case 0x1337B4u: goto label_1337b4;
            case 0x1337F0u: goto label_1337f0;
            case 0x133804u: goto label_133804;
            case 0x133828u: goto label_133828;
            case 0x133830u: goto label_133830;
            case 0x133858u: goto label_133858;
            case 0x13389Cu: goto label_13389c;
            case 0x1338A8u: goto label_1338a8;
            case 0x1338B4u: goto label_1338b4;
            case 0x1338C0u: goto label_1338c0;
            case 0x1338D0u: goto label_1338d0;
            case 0x1338E0u: goto label_1338e0;
            case 0x1338ECu: goto label_1338ec;
            case 0x1338F8u: goto label_1338f8;
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            case 0x133AE8u: goto label_133ae8;
            case 0x133B10u: goto label_133b10;
            case 0x133B20u: goto label_133b20;
            case 0x133B28u: goto label_133b28;
            case 0x133B30u: goto label_133b30;
            case 0x133B34u: goto label_133b34;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133A4Cu; }
            if (ctx->pc != 0x133A4Cu) { return; }
        }
        }
    }
    ctx->pc = 0x133A4Cu;
label_133a4c:
    // 0x133a4c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x133a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x133a50: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x133a50u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a54: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x133a54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a58: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x133a58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x133a5c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x133a5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x133a60: 0x60f809  jalr        $v1
    ctx->pc = 0x133A60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x133A68u);
        ctx->pc = 0x133A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133A60u;
            // 0x133a64: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133A68u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1334C0u: goto label_1334c0;
            case 0x1334C8u: goto label_1334c8;
            case 0x1334D0u: goto label_1334d0;
            case 0x1334ECu: goto label_1334ec;
            case 0x133514u: goto label_133514;
            case 0x133524u: goto label_133524;
            case 0x133538u: goto label_133538;
            case 0x133568u: goto label_133568;
            case 0x13356Cu: goto label_13356c;
            case 0x1335A4u: goto label_1335a4;
            case 0x1335C0u: goto label_1335c0;
            case 0x1335C8u: goto label_1335c8;
            case 0x1335D4u: goto label_1335d4;
            case 0x133630u: goto label_133630;
            case 0x133664u: goto label_133664;
            case 0x133668u: goto label_133668;
            case 0x133688u: goto label_133688;
            case 0x133690u: goto label_133690;
            case 0x133698u: goto label_133698;
            case 0x1336A4u: goto label_1336a4;
            case 0x1336B8u: goto label_1336b8;
            case 0x1336D8u: goto label_1336d8;
            case 0x1336E0u: goto label_1336e0;
            case 0x133740u: goto label_133740;
            case 0x133744u: goto label_133744;
            case 0x133768u: goto label_133768;
            case 0x133770u: goto label_133770;
            case 0x1337B4u: goto label_1337b4;
            case 0x1337F0u: goto label_1337f0;
            case 0x133804u: goto label_133804;
            case 0x133828u: goto label_133828;
            case 0x133830u: goto label_133830;
            case 0x133858u: goto label_133858;
            case 0x13389Cu: goto label_13389c;
            case 0x1338A8u: goto label_1338a8;
            case 0x1338B4u: goto label_1338b4;
            case 0x1338C0u: goto label_1338c0;
            case 0x1338D0u: goto label_1338d0;
            case 0x1338E0u: goto label_1338e0;
            case 0x1338ECu: goto label_1338ec;
            case 0x1338F8u: goto label_1338f8;
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            case 0x133AE8u: goto label_133ae8;
            case 0x133B10u: goto label_133b10;
            case 0x133B20u: goto label_133b20;
            case 0x133B28u: goto label_133b28;
            case 0x133B30u: goto label_133b30;
            case 0x133B34u: goto label_133b34;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133A68u; }
            if (ctx->pc != 0x133A68u) { return; }
        }
        }
    }
    ctx->pc = 0x133A68u;
label_133a68:
    // 0x133a68: 0x8e060000  lw          $a2, 0x0($s0)
    ctx->pc = 0x133a68u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x133a6c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x133a6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a70: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x133a70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a74: 0x8cc20020  lw          $v0, 0x20($a2)
    ctx->pc = 0x133a74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x133a78: 0x40f809  jalr        $v0
    ctx->pc = 0x133A78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133A80u);
        ctx->pc = 0x133A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133A78u;
            // 0x133a7c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133A80u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1334C0u: goto label_1334c0;
            case 0x1334C8u: goto label_1334c8;
            case 0x1334D0u: goto label_1334d0;
            case 0x1334ECu: goto label_1334ec;
            case 0x133514u: goto label_133514;
            case 0x133524u: goto label_133524;
            case 0x133538u: goto label_133538;
            case 0x133568u: goto label_133568;
            case 0x13356Cu: goto label_13356c;
            case 0x1335A4u: goto label_1335a4;
            case 0x1335C0u: goto label_1335c0;
            case 0x1335C8u: goto label_1335c8;
            case 0x1335D4u: goto label_1335d4;
            case 0x133630u: goto label_133630;
            case 0x133664u: goto label_133664;
            case 0x133668u: goto label_133668;
            case 0x133688u: goto label_133688;
            case 0x133690u: goto label_133690;
            case 0x133698u: goto label_133698;
            case 0x1336A4u: goto label_1336a4;
            case 0x1336B8u: goto label_1336b8;
            case 0x1336D8u: goto label_1336d8;
            case 0x1336E0u: goto label_1336e0;
            case 0x133740u: goto label_133740;
            case 0x133744u: goto label_133744;
            case 0x133768u: goto label_133768;
            case 0x133770u: goto label_133770;
            case 0x1337B4u: goto label_1337b4;
            case 0x1337F0u: goto label_1337f0;
            case 0x133804u: goto label_133804;
            case 0x133828u: goto label_133828;
            case 0x133830u: goto label_133830;
            case 0x133858u: goto label_133858;
            case 0x13389Cu: goto label_13389c;
            case 0x1338A8u: goto label_1338a8;
            case 0x1338B4u: goto label_1338b4;
            case 0x1338C0u: goto label_1338c0;
            case 0x1338D0u: goto label_1338d0;
            case 0x1338E0u: goto label_1338e0;
            case 0x1338ECu: goto label_1338ec;
            case 0x1338F8u: goto label_1338f8;
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            case 0x133AE8u: goto label_133ae8;
            case 0x133B10u: goto label_133b10;
            case 0x133B20u: goto label_133b20;
            case 0x133B28u: goto label_133b28;
            case 0x133B30u: goto label_133b30;
            case 0x133B34u: goto label_133b34;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133A80u; }
            if (ctx->pc != 0x133A80u) { return; }
        }
        }
    }
    ctx->pc = 0x133A80u;
label_133a80:
    // 0x133a80: 0xc04b694  jal         func_12DA50
    ctx->pc = 0x133A80u;
    SET_GPR_U32(ctx, 31, 0x133A88u);
    ctx->pc = 0x133A84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133A80u;
            // 0x133a84: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DA50u;
    if (runtime->hasFunction(0x12DA50u)) {
        auto targetFn = runtime->lookupFunction(0x12DA50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A88u; }
        if (ctx->pc != 0x133A88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DA50_0x12da50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A88u; }
        if (ctx->pc != 0x133A88u) { return; }
    }
    ctx->pc = 0x133A88u;
label_133a88:
    // 0x133a88: 0x8e22004c  lw          $v0, 0x4C($s1)
    ctx->pc = 0x133a88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 76)));
    // 0x133a8c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x133a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x133a90: 0xae22004c  sw          $v0, 0x4C($s1)
    ctx->pc = 0x133a90u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 76), GPR_U32(ctx, 2));
    // 0x133a94: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x133a94u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_133a98:
    // 0x133a98: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x133a98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x133a9c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x133a9cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x133aa0: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x133aa0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x133aa4: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x133aa4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x133aa8: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x133aa8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x133aac: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x133aacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x133ab0: 0x3e00008  jr          $ra
    ctx->pc = 0x133AB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x133AB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133AB0u;
            // 0x133ab4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1334C0u: goto label_1334c0;
            case 0x1334C8u: goto label_1334c8;
            case 0x1334D0u: goto label_1334d0;
            case 0x1334ECu: goto label_1334ec;
            case 0x133514u: goto label_133514;
            case 0x133524u: goto label_133524;
            case 0x133538u: goto label_133538;
            case 0x133568u: goto label_133568;
            case 0x13356Cu: goto label_13356c;
            case 0x1335A4u: goto label_1335a4;
            case 0x1335C0u: goto label_1335c0;
            case 0x1335C8u: goto label_1335c8;
            case 0x1335D4u: goto label_1335d4;
            case 0x133630u: goto label_133630;
            case 0x133664u: goto label_133664;
            case 0x133668u: goto label_133668;
            case 0x133688u: goto label_133688;
            case 0x133690u: goto label_133690;
            case 0x133698u: goto label_133698;
            case 0x1336A4u: goto label_1336a4;
            case 0x1336B8u: goto label_1336b8;
            case 0x1336D8u: goto label_1336d8;
            case 0x1336E0u: goto label_1336e0;
            case 0x133740u: goto label_133740;
            case 0x133744u: goto label_133744;
            case 0x133768u: goto label_133768;
            case 0x133770u: goto label_133770;
            case 0x1337B4u: goto label_1337b4;
            case 0x1337F0u: goto label_1337f0;
            case 0x133804u: goto label_133804;
            case 0x133828u: goto label_133828;
            case 0x133830u: goto label_133830;
            case 0x133858u: goto label_133858;
            case 0x13389Cu: goto label_13389c;
            case 0x1338A8u: goto label_1338a8;
            case 0x1338B4u: goto label_1338b4;
            case 0x1338C0u: goto label_1338c0;
            case 0x1338D0u: goto label_1338d0;
            case 0x1338E0u: goto label_1338e0;
            case 0x1338ECu: goto label_1338ec;
            case 0x1338F8u: goto label_1338f8;
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            case 0x133AE8u: goto label_133ae8;
            case 0x133B10u: goto label_133b10;
            case 0x133B20u: goto label_133b20;
            case 0x133B28u: goto label_133b28;
            case 0x133B30u: goto label_133b30;
            case 0x133B34u: goto label_133b34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133AB8u;
    // 0x133ab8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x133ab8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x133abc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x133abcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x133ac0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x133ac0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133ac4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x133ac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x133ac8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x133ac8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x133acc: 0x8e110008  lw          $s1, 0x8($s0)
    ctx->pc = 0x133accu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x133ad0: 0x12200017  beqz        $s1, . + 4 + (0x17 << 2)
    ctx->pc = 0x133AD0u;
    {
        const bool branch_taken_0x133ad0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x133AD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133AD0u;
            // 0x133ad4: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133ad0) {
            ctx->pc = 0x133B30u;
            goto label_133b30;
        }
    }
    ctx->pc = 0x133AD8u;
    // 0x133ad8: 0x50800016  beql        $a0, $zero, . + 4 + (0x16 << 2)
    ctx->pc = 0x133AD8u;
    {
        const bool branch_taken_0x133ad8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x133ad8) {
            ctx->pc = 0x133ADCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x133AD8u;
            // 0x133adc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x133B34u;
            goto label_133b34;
        }
    }
    ctx->pc = 0x133AE0u;
    // 0x133ae0: 0xc04b620  jal         func_12D880
    ctx->pc = 0x133AE0u;
    SET_GPR_U32(ctx, 31, 0x133AE8u);
    ctx->pc = 0x12D880u;
    if (runtime->hasFunction(0x12D880u)) {
        auto targetFn = runtime->lookupFunction(0x12D880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133AE8u; }
        if (ctx->pc != 0x133AE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D880_0x12d880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133AE8u; }
        if (ctx->pc != 0x133AE8u) { return; }
    }
    ctx->pc = 0x133AE8u;
label_133ae8:
    // 0x133ae8: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x133ae8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x133aec: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x133aecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133af0: 0x24c207ff  addiu       $v0, $a2, 0x7FF
    ctx->pc = 0x133af0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 2047));
    // 0x133af4: 0x28c30000  slti        $v1, $a2, 0x0
    ctx->pc = 0x133af4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x133af8: 0x43300b  movn        $a2, $v0, $v1
    ctx->pc = 0x133af8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 2));
    // 0x133afc: 0x8202006c  lb          $v0, 0x6C($s0)
    ctx->pc = 0x133afcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 108)));
    // 0x133b00: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x133B00u;
    {
        const bool branch_taken_0x133b00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x133B04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133B00u;
            // 0x133b04: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133b00) {
            ctx->pc = 0x133B28u;
            goto label_133b28;
        }
    }
    ctx->pc = 0x133B08u;
    // 0x133b08: 0xc04b5d2  jal         func_12D748
    ctx->pc = 0x133B08u;
    SET_GPR_U32(ctx, 31, 0x133B10u);
    ctx->pc = 0x133B0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133B08u;
            // 0x133b0c: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D748u;
    if (runtime->hasFunction(0x12D748u)) {
        auto targetFn = runtime->lookupFunction(0x12D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B10u; }
        if (ctx->pc != 0x133B10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D748_0x12d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B10u; }
        if (ctx->pc != 0x133B10u) { return; }
    }
    ctx->pc = 0x133B10u;
label_133b10:
    // 0x133b10: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x133b10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x133b14: 0x3c057fff  lui         $a1, 0x7FFF
    ctx->pc = 0x133b14u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32767 << 16));
    // 0x133b18: 0xc04c1ea  jal         func_1307A8
    ctx->pc = 0x133B18u;
    SET_GPR_U32(ctx, 31, 0x133B20u);
    ctx->pc = 0x133B1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133B18u;
            // 0x133b1c: 0x34a5ffff  ori         $a1, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1307A8u;
    if (runtime->hasFunction(0x1307A8u)) {
        auto targetFn = runtime->lookupFunction(0x1307A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B20u; }
        if (ctx->pc != 0x133B20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001307A8_0x1307a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B20u; }
        if (ctx->pc != 0x133B20u) { return; }
    }
    ctx->pc = 0x133B20u;
label_133b20:
    // 0x133b20: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x133B20u;
    {
        const bool branch_taken_0x133b20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x133B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133B20u;
            // 0x133b24: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133b20) {
            ctx->pc = 0x133B34u;
            goto label_133b34;
        }
    }
    ctx->pc = 0x133B28u;
label_133b28:
    // 0x133b28: 0xc04c170  jal         func_1305C0
    ctx->pc = 0x133B28u;
    SET_GPR_U32(ctx, 31, 0x133B30u);
    ctx->pc = 0x133B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133B28u;
            // 0x133b2c: 0x62ac3  sra         $a1, $a2, 11 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 6), 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305C0u;
    if (runtime->hasFunction(0x1305C0u)) {
        auto targetFn = runtime->lookupFunction(0x1305C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B30u; }
        if (ctx->pc != 0x133B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305C0_0x1305c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B30u; }
        if (ctx->pc != 0x133B30u) { return; }
    }
    ctx->pc = 0x133B30u;
label_133b30:
    // 0x133b30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x133b30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_133b34:
    // 0x133b34: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133b34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133b38: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x133b38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133b3c: 0x3e00008  jr          $ra
    ctx->pc = 0x133B3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x133B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133B3Cu;
            // 0x133b40: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1334C0u: goto label_1334c0;
            case 0x1334C8u: goto label_1334c8;
            case 0x1334D0u: goto label_1334d0;
            case 0x1334ECu: goto label_1334ec;
            case 0x133514u: goto label_133514;
            case 0x133524u: goto label_133524;
            case 0x133538u: goto label_133538;
            case 0x133568u: goto label_133568;
            case 0x13356Cu: goto label_13356c;
            case 0x1335A4u: goto label_1335a4;
            case 0x1335C0u: goto label_1335c0;
            case 0x1335C8u: goto label_1335c8;
            case 0x1335D4u: goto label_1335d4;
            case 0x133630u: goto label_133630;
            case 0x133664u: goto label_133664;
            case 0x133668u: goto label_133668;
            case 0x133688u: goto label_133688;
            case 0x133690u: goto label_133690;
            case 0x133698u: goto label_133698;
            case 0x1336A4u: goto label_1336a4;
            case 0x1336B8u: goto label_1336b8;
            case 0x1336D8u: goto label_1336d8;
            case 0x1336E0u: goto label_1336e0;
            case 0x133740u: goto label_133740;
            case 0x133744u: goto label_133744;
            case 0x133768u: goto label_133768;
            case 0x133770u: goto label_133770;
            case 0x1337B4u: goto label_1337b4;
            case 0x1337F0u: goto label_1337f0;
            case 0x133804u: goto label_133804;
            case 0x133828u: goto label_133828;
            case 0x133830u: goto label_133830;
            case 0x133858u: goto label_133858;
            case 0x13389Cu: goto label_13389c;
            case 0x1338A8u: goto label_1338a8;
            case 0x1338B4u: goto label_1338b4;
            case 0x1338C0u: goto label_1338c0;
            case 0x1338D0u: goto label_1338d0;
            case 0x1338E0u: goto label_1338e0;
            case 0x1338ECu: goto label_1338ec;
            case 0x1338F8u: goto label_1338f8;
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            case 0x133AE8u: goto label_133ae8;
            case 0x133B10u: goto label_133b10;
            case 0x133B20u: goto label_133b20;
            case 0x133B28u: goto label_133b28;
            case 0x133B30u: goto label_133b30;
            case 0x133B34u: goto label_133b34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133B44u;
    // 0x133b44: 0x0  nop
    ctx->pc = 0x133b44u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
