#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108490
// Address: 0x108490 - 0x108590
void sub_00108490_0x108490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108490_0x108490");
#endif

    switch (ctx->pc) {
        case 0x1084d4u: goto label_1084d4;
        case 0x1084fcu: goto label_1084fc;
        case 0x108510u: goto label_108510;
        case 0x108528u: goto label_108528;
        case 0x108554u: goto label_108554;
        case 0x108564u: goto label_108564;
        default: break;
    }

    ctx->pc = 0x108490u;

    // 0x108490: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x108490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x108494: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x108494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x108498: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x108498u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10849c: 0x32220003  andi        $v0, $s1, 0x3
    ctx->pc = 0x10849cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)3);
    // 0x1084a0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1084a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1084a4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1084a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1084a8: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1084a8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1084ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1084acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1084b0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1084b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1084b4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1084B4u;
    {
        const bool branch_taken_0x1084b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1084B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1084B4u;
            // 0x1084b8: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1084b4) {
            ctx->pc = 0x1084D8u;
            goto label_1084d8;
        }
    }
    ctx->pc = 0x1084BCu;
    // 0x1084bc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1084bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1084c0: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x1084c0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x1084c4: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x1084c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1084c8: 0x8cc67914  lw          $a2, 0x7914($a2)
    ctx->pc = 0x1084c8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 30996)));
    // 0x1084cc: 0xc041fb4  jal         func_107ED0
    ctx->pc = 0x1084CCu;
    SET_GPR_U32(ctx, 31, 0x1084D4u);
    ctx->pc = 0x1084D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1084CCu;
            // 0x1084d0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107ED0u;
    if (runtime->hasFunction(0x107ED0u)) {
        auto targetFn = runtime->lookupFunction(0x107ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1084D4u; }
        if (ctx->pc != 0x1084D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107ED0_0x107ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1084D4u; }
        if (ctx->pc != 0x1084D4u) { return; }
    }
    ctx->pc = 0x1084D4u;
label_1084d4:
    // 0x1084d4: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1084d4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1084d8:
    // 0x1084d8: 0x118883  sra         $s1, $s1, 2
    ctx->pc = 0x1084d8u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 2));
    // 0x1084dc: 0x12200024  beqz        $s1, . + 4 + (0x24 << 2)
    ctx->pc = 0x1084DCu;
    {
        const bool branch_taken_0x1084dc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1084E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1084DCu;
            // 0x1084e0: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1084dc) {
            ctx->pc = 0x108570u;
            goto label_108570;
        }
    }
    ctx->pc = 0x1084E4u;
    // 0x1084e4: 0x8e700048  lw          $s0, 0x48($s3)
    ctx->pc = 0x1084e4u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 72)));
    // 0x1084e8: 0x16000014  bnez        $s0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1084E8u;
    {
        const bool branch_taken_0x1084e8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1084ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1084E8u;
            // 0x1084ec: 0x32220001  andi        $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1084e8) {
            ctx->pc = 0x10853Cu;
            goto label_10853c;
        }
    }
    ctx->pc = 0x1084F0u;
    // 0x1084f0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1084f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1084f4: 0xc042092  jal         func_108248
    ctx->pc = 0x1084F4u;
    SET_GPR_U32(ctx, 31, 0x1084FCu);
    ctx->pc = 0x1084F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1084F4u;
            // 0x1084f8: 0x24050271  addiu       $a1, $zero, 0x271 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 625));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108248u;
    if (runtime->hasFunction(0x108248u)) {
        auto targetFn = runtime->lookupFunction(0x108248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1084FCu; }
        if (ctx->pc != 0x1084FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108248_0x108248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1084FCu; }
        if (ctx->pc != 0x1084FCu) { return; }
    }
    ctx->pc = 0x1084FCu;
label_1084fc:
    // 0x1084fc: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1084fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108500: 0xae620048  sw          $v0, 0x48($s3)
    ctx->pc = 0x108500u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 72), GPR_U32(ctx, 2));
    // 0x108504: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x108504u;
    {
        const bool branch_taken_0x108504 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108504u;
            // 0x108508: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108504) {
            ctx->pc = 0x108538u;
            goto label_108538;
        }
    }
    ctx->pc = 0x10850Cu;
    // 0x10850c: 0x0  nop
    ctx->pc = 0x10850cu;
    // NOP
label_108510:
    // 0x108510: 0x54600009  bnel        $v1, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x108510u;
    {
        const bool branch_taken_0x108510 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x108510) {
            ctx->pc = 0x108514u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x108510u;
            // 0x108514: 0x60802d  daddu       $s0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108538u;
            goto label_108538;
        }
    }
    ctx->pc = 0x108518u;
    // 0x108518: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x108518u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10851c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x10851cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108520: 0xc0420a0  jal         func_108280
    ctx->pc = 0x108520u;
    SET_GPR_U32(ctx, 31, 0x108528u);
    ctx->pc = 0x108524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108520u;
            // 0x108524: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108280u;
    if (runtime->hasFunction(0x108280u)) {
        auto targetFn = runtime->lookupFunction(0x108280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108528u; }
        if (ctx->pc != 0x108528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108280_0x108280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108528u; }
        if (ctx->pc != 0x108528u) { return; }
    }
    ctx->pc = 0x108528u;
label_108528:
    // 0x108528: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x108528u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10852c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x10852cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x108530: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x108530u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x108534: 0x60802d  daddu       $s0, $v1, $zero
    ctx->pc = 0x108534u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_108538:
    // 0x108538: 0x32220001  andi        $v0, $s1, 0x1
    ctx->pc = 0x108538u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
label_10853c:
    // 0x10853c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10853Cu;
    {
        const bool branch_taken_0x10853c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x108540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10853Cu;
            // 0x108540: 0x118843  sra         $s1, $s1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10853c) {
            ctx->pc = 0x108564u;
            goto label_108564;
        }
    }
    ctx->pc = 0x108544u;
    // 0x108544: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x108544u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108548: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x108548u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10854c: 0xc0420a0  jal         func_108280
    ctx->pc = 0x10854Cu;
    SET_GPR_U32(ctx, 31, 0x108554u);
    ctx->pc = 0x108550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10854Cu;
            // 0x108550: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108280u;
    if (runtime->hasFunction(0x108280u)) {
        auto targetFn = runtime->lookupFunction(0x108280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108554u; }
        if (ctx->pc != 0x108554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108280_0x108280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108554u; }
        if (ctx->pc != 0x108554u) { return; }
    }
    ctx->pc = 0x108554u;
label_108554:
    // 0x108554: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x108554u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108558: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x108558u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10855c: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10855Cu;
    SET_GPR_U32(ctx, 31, 0x108564u);
    ctx->pc = 0x108560u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10855Cu;
            // 0x108560: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108564u; }
        if (ctx->pc != 0x108564u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108564u; }
        if (ctx->pc != 0x108564u) { return; }
    }
    ctx->pc = 0x108564u;
label_108564:
    // 0x108564: 0x5620ffea  bnel        $s1, $zero, . + 4 + (-0x16 << 2)
    ctx->pc = 0x108564u;
    {
        const bool branch_taken_0x108564 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x108564) {
            ctx->pc = 0x108568u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x108564u;
            // 0x108568: 0x8e030000  lw          $v1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108510u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108510;
        }
    }
    ctx->pc = 0x10856Cu;
    // 0x10856c: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x10856cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_108570:
    // 0x108570: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x108570u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x108574: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x108574u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x108578: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x108578u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10857c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x10857cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x108580: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x108580u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x108584: 0x3e00008  jr          $ra
    ctx->pc = 0x108584u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x108588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108584u;
            // 0x108588: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1084D4u: goto label_1084d4;
            case 0x1084D8u: goto label_1084d8;
            case 0x1084FCu: goto label_1084fc;
            case 0x108510u: goto label_108510;
            case 0x108528u: goto label_108528;
            case 0x108538u: goto label_108538;
            case 0x10853Cu: goto label_10853c;
            case 0x108554u: goto label_108554;
            case 0x108564u: goto label_108564;
            case 0x108570u: goto label_108570;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10858Cu;
    // 0x10858c: 0x0  nop
    ctx->pc = 0x10858cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
