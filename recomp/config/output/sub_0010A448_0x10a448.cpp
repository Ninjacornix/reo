#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A448
// Address: 0x10a448 - 0x10a6a8
void sub_0010A448_0x10a448(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A448_0x10a448");
#endif

    switch (ctx->pc) {
        case 0x10a46cu: goto label_10a46c;
        case 0x10a488u: goto label_10a488;
        case 0x10a504u: goto label_10a504;
        case 0x10a57cu: goto label_10a57c;
        case 0x10a5a4u: goto label_10a5a4;
        case 0x10a5f8u: goto label_10a5f8;
        case 0x10a648u: goto label_10a648;
        case 0x10a690u: goto label_10a690;
        default: break;
    }

    ctx->pc = 0x10a448u;

label_10a448:
    // 0x10a448: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10a448u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10a44c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a44cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a450: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10a450u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a454: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x10a454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x10a458: 0x8e0201d4  lw          $v0, 0x1D4($s0)
    ctx->pc = 0x10a458u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 468)));
    // 0x10a45c: 0x54400012  bnel        $v0, $zero, . + 4 + (0x12 << 2)
    ctx->pc = 0x10A45Cu;
    {
        const bool branch_taken_0x10a45c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10a45c) {
            ctx->pc = 0x10A460u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A45Cu;
            // 0x10a460: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A4A8u;
            goto label_10a4a8;
        }
    }
    ctx->pc = 0x10A464u;
    // 0x10a464: 0xc041c76  jal         func_1071D8
    ctx->pc = 0x10A464u;
    SET_GPR_U32(ctx, 31, 0x10A46Cu);
    ctx->pc = 0x10A468u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A464u;
            // 0x10a468: 0x24050080  addiu       $a1, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1071D8u;
    if (runtime->hasFunction(0x1071D8u)) {
        auto targetFn = runtime->lookupFunction(0x1071D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A46Cu; }
        if (ctx->pc != 0x10A46Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001071D8_0x1071d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A46Cu; }
        if (ctx->pc != 0x10A46Cu) { return; }
    }
    ctx->pc = 0x10A46Cu;
label_10a46c:
    // 0x10a46c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x10a46cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a470: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10a470u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a474: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x10A474u;
    {
        const bool branch_taken_0x10a474 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A474u;
            // 0x10a478: 0xae0301d4  sw          $v1, 0x1D4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 468), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a474) {
            ctx->pc = 0x10A4A8u;
            goto label_10a4a8;
        }
    }
    ctx->pc = 0x10A47Cu;
    // 0x10a47c: 0x2462007c  addiu       $v0, $v1, 0x7C
    ctx->pc = 0x10a47cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 124));
    // 0x10a480: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x10a480u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x10a484: 0x0  nop
    ctx->pc = 0x10a484u;
    // NOP
label_10a488:
    // 0x10a488: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x10a488u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x10a48c: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x10a48cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x10a490: 0x0  nop
    ctx->pc = 0x10a490u;
    // NOP
    // 0x10a494: 0x0  nop
    ctx->pc = 0x10a494u;
    // NOP
    // 0x10a498: 0x0  nop
    ctx->pc = 0x10a498u;
    // NOP
    // 0x10a49c: 0x461fffa  bgez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10A49Cu;
    {
        const bool branch_taken_0x10a49c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x10A4A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A49Cu;
            // 0x10a4a0: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a49c) {
            ctx->pc = 0x10A488u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10a488;
        }
    }
    ctx->pc = 0x10A4A4u;
    // 0x10a4a4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10a4a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10a4a8:
    // 0x10a4a8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a4a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a4ac: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x10a4acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a4b0: 0x3e00008  jr          $ra
    ctx->pc = 0x10A4B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A4B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A4B0u;
            // 0x10a4b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A448u: goto label_10a448;
            case 0x10A46Cu: goto label_10a46c;
            case 0x10A488u: goto label_10a488;
            case 0x10A4A8u: goto label_10a4a8;
            case 0x10A4F0u: goto label_10a4f0;
            case 0x10A504u: goto label_10a504;
            case 0x10A514u: goto label_10a514;
            case 0x10A520u: goto label_10a520;
            case 0x10A568u: goto label_10a568;
            case 0x10A57Cu: goto label_10a57c;
            case 0x10A58Cu: goto label_10a58c;
            case 0x10A5A4u: goto label_10a5a4;
            case 0x10A5C8u: goto label_10a5c8;
            case 0x10A5F0u: goto label_10a5f0;
            case 0x10A5F8u: goto label_10a5f8;
            case 0x10A5FCu: goto label_10a5fc;
            case 0x10A648u: goto label_10a648;
            case 0x10A658u: goto label_10a658;
            case 0x10A65Cu: goto label_10a65c;
            case 0x10A690u: goto label_10a690;
            case 0x10A694u: goto label_10a694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A4B8u;
    // 0x10a4b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10a4b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10a4bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10a4bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10a4c0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x10a4c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a4c4: 0x2e220020  sltiu       $v0, $s1, 0x20
    ctx->pc = 0x10a4c4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x10a4c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a4c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a4cc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x10a4ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x10a4d0: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x10a4d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a4d4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x10a4d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x10a4d8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10A4D8u;
    {
        const bool branch_taken_0x10a4d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A4DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A4D8u;
            // 0x10a4dc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a4d8) {
            ctx->pc = 0x10A4F0u;
            goto label_10a4f0;
        }
    }
    ctx->pc = 0x10A4E0u;
    // 0x10a4e0: 0x24030016  addiu       $v1, $zero, 0x16
    ctx->pc = 0x10a4e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x10a4e4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10a4e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a4e8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x10A4E8u;
    {
        const bool branch_taken_0x10a4e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A4ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A4E8u;
            // 0x10a4ec: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a4e8) {
            ctx->pc = 0x10A520u;
            goto label_10a520;
        }
    }
    ctx->pc = 0x10A4F0u;
label_10a4f0:
    // 0x10a4f0: 0x8e0201d4  lw          $v0, 0x1D4($s0)
    ctx->pc = 0x10a4f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 468)));
    // 0x10a4f4: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10A4F4u;
    {
        const bool branch_taken_0x10a4f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A4F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A4F4u;
            // 0x10a4f8: 0x111880  sll         $v1, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a4f4) {
            ctx->pc = 0x10A514u;
            goto label_10a514;
        }
    }
    ctx->pc = 0x10A4FCu;
    // 0x10a4fc: 0xc042912  jal         func_10A448
    ctx->pc = 0x10A4FCu;
    SET_GPR_U32(ctx, 31, 0x10A504u);
    ctx->pc = 0x10A448u;
    goto label_10a448;
    ctx->pc = 0x10A504u;
label_10a504:
    // 0x10a504: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10A504u;
    {
        const bool branch_taken_0x10a504 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A504u;
            // 0x10a508: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a504) {
            ctx->pc = 0x10A520u;
            goto label_10a520;
        }
    }
    ctx->pc = 0x10A50Cu;
    // 0x10a50c: 0x8e0201d4  lw          $v0, 0x1D4($s0)
    ctx->pc = 0x10a50cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 468)));
    // 0x10a510: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x10a510u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
label_10a514:
    // 0x10a514: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10a514u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10a518: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x10a518u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10a51c: 0xac720000  sw          $s2, 0x0($v1)
    ctx->pc = 0x10a51cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 18));
label_10a520:
    // 0x10a520: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a520u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a524: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10a524u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a528: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x10a528u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10a52c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x10a52cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10a530: 0x3e00008  jr          $ra
    ctx->pc = 0x10A530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A530u;
            // 0x10a534: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A448u: goto label_10a448;
            case 0x10A46Cu: goto label_10a46c;
            case 0x10A488u: goto label_10a488;
            case 0x10A4A8u: goto label_10a4a8;
            case 0x10A4F0u: goto label_10a4f0;
            case 0x10A504u: goto label_10a504;
            case 0x10A514u: goto label_10a514;
            case 0x10A520u: goto label_10a520;
            case 0x10A568u: goto label_10a568;
            case 0x10A57Cu: goto label_10a57c;
            case 0x10A58Cu: goto label_10a58c;
            case 0x10A5A4u: goto label_10a5a4;
            case 0x10A5C8u: goto label_10a5c8;
            case 0x10A5F0u: goto label_10a5f0;
            case 0x10A5F8u: goto label_10a5f8;
            case 0x10A5FCu: goto label_10a5fc;
            case 0x10A648u: goto label_10a648;
            case 0x10A658u: goto label_10a658;
            case 0x10A65Cu: goto label_10a65c;
            case 0x10A690u: goto label_10a690;
            case 0x10A694u: goto label_10a694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A538u;
    // 0x10a538: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10a538u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10a53c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10a53cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10a540: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x10a540u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a544: 0x2e220020  sltiu       $v0, $s1, 0x20
    ctx->pc = 0x10a544u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x10a548: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a548u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a54c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x10a54cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x10a550: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10A550u;
    {
        const bool branch_taken_0x10a550 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A550u;
            // 0x10a554: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a550) {
            ctx->pc = 0x10A568u;
            goto label_10a568;
        }
    }
    ctx->pc = 0x10A558u;
    // 0x10a558: 0x24030016  addiu       $v1, $zero, 0x16
    ctx->pc = 0x10a558u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x10a55c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10a55cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a560: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x10A560u;
    {
        const bool branch_taken_0x10a560 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A560u;
            // 0x10a564: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a560) {
            ctx->pc = 0x10A5FCu;
            goto label_10a5fc;
        }
    }
    ctx->pc = 0x10A568u;
label_10a568:
    // 0x10a568: 0x8e0301d4  lw          $v1, 0x1D4($s0)
    ctx->pc = 0x10a568u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 468)));
    // 0x10a56c: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x10A56Cu;
    {
        const bool branch_taken_0x10a56c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A56Cu;
            // 0x10a570: 0x111080  sll         $v0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a56c) {
            ctx->pc = 0x10A58Cu;
            goto label_10a58c;
        }
    }
    ctx->pc = 0x10A574u;
    // 0x10a574: 0xc042912  jal         func_10A448
    ctx->pc = 0x10A574u;
    SET_GPR_U32(ctx, 31, 0x10A57Cu);
    ctx->pc = 0x10A448u;
    goto label_10a448;
    ctx->pc = 0x10A57Cu;
label_10a57c:
    // 0x10a57c: 0x1440001f  bnez        $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x10A57Cu;
    {
        const bool branch_taken_0x10a57c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A57Cu;
            // 0x10a580: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a57c) {
            ctx->pc = 0x10A5FCu;
            goto label_10a5fc;
        }
    }
    ctx->pc = 0x10A584u;
    // 0x10a584: 0x8e0301d4  lw          $v1, 0x1D4($s0)
    ctx->pc = 0x10a584u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 468)));
    // 0x10a588: 0x111080  sll         $v0, $s1, 2
    ctx->pc = 0x10a588u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
label_10a58c:
    // 0x10a58c: 0x432021  addu        $a0, $v0, $v1
    ctx->pc = 0x10a58cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10a590: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x10a590u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10a594: 0x54a0000c  bnel        $a1, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x10A594u;
    {
        const bool branch_taken_0x10a594 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x10a594) {
            ctx->pc = 0x10A598u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A594u;
            // 0x10a598: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A5C8u;
            goto label_10a5c8;
        }
    }
    ctx->pc = 0x10A59Cu;
    // 0x10a59c: 0xc0429e4  jal         func_10A790
    ctx->pc = 0x10A59Cu;
    SET_GPR_U32(ctx, 31, 0x10A5A4u);
    ctx->pc = 0x10A5A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A59Cu;
            // 0x10a5a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A790u;
    if (runtime->hasFunction(0x10A790u)) {
        auto targetFn = runtime->lookupFunction(0x10A790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A5A4u; }
        if (ctx->pc != 0x10A5A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A790_0x10a790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A5A4u; }
        if (ctx->pc != 0x10A5A4u) { return; }
    }
    ctx->pc = 0x10A5A4u;
label_10a5a4:
    // 0x10a5a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10a5a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a5a8: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x10a5a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a5ac: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10a5acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a5b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a5b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a5b4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10a5b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a5b8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x10a5b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10a5bc: 0x80429cc  j           func_10A730
    ctx->pc = 0x10A5BCu;
    ctx->pc = 0x10A5C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A5BCu;
            // 0x10a5c0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A730u;
    if (runtime->hasFunction(0x10A730u)) {
        auto targetFn = runtime->lookupFunction(0x10A730u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010A730_0x10a730(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10A5C4u;
    // 0x10a5c4: 0x0  nop
    ctx->pc = 0x10a5c4u;
    // NOP
label_10a5c8:
    // 0x10a5c8: 0x10a3000c  beq         $a1, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x10A5C8u;
    {
        const bool branch_taken_0x10a5c8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x10A5CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A5C8u;
            // 0x10a5cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a5c8) {
            ctx->pc = 0x10A5FCu;
            goto label_10a5fc;
        }
    }
    ctx->pc = 0x10A5D0u;
    // 0x10a5d0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10a5d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a5d4: 0x54a20006  bnel        $a1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10A5D4u;
    {
        const bool branch_taken_0x10a5d4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0x10a5d4) {
            ctx->pc = 0x10A5D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A5D4u;
            // 0x10a5d8: 0xac800000  sw          $zero, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A5F0u;
            goto label_10a5f0;
        }
    }
    ctx->pc = 0x10A5DCu;
    // 0x10a5dc: 0x24030016  addiu       $v1, $zero, 0x16
    ctx->pc = 0x10a5dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x10a5e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10a5e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10a5e4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10A5E4u;
    {
        const bool branch_taken_0x10a5e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A5E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A5E4u;
            // 0x10a5e8: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a5e4) {
            ctx->pc = 0x10A5FCu;
            goto label_10a5fc;
        }
    }
    ctx->pc = 0x10A5ECu;
    // 0x10a5ec: 0x0  nop
    ctx->pc = 0x10a5ecu;
    // NOP
label_10a5f0:
    // 0x10a5f0: 0xa0f809  jalr        $a1
    ctx->pc = 0x10A5F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 5);
        SET_GPR_U32(ctx, 31, 0x10A5F8u);
        ctx->pc = 0x10A5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A5F0u;
            // 0x10a5f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x10A5F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A448u: goto label_10a448;
            case 0x10A46Cu: goto label_10a46c;
            case 0x10A488u: goto label_10a488;
            case 0x10A4A8u: goto label_10a4a8;
            case 0x10A4F0u: goto label_10a4f0;
            case 0x10A504u: goto label_10a504;
            case 0x10A514u: goto label_10a514;
            case 0x10A520u: goto label_10a520;
            case 0x10A568u: goto label_10a568;
            case 0x10A57Cu: goto label_10a57c;
            case 0x10A58Cu: goto label_10a58c;
            case 0x10A5A4u: goto label_10a5a4;
            case 0x10A5C8u: goto label_10a5c8;
            case 0x10A5F0u: goto label_10a5f0;
            case 0x10A5F8u: goto label_10a5f8;
            case 0x10A5FCu: goto label_10a5fc;
            case 0x10A648u: goto label_10a648;
            case 0x10A658u: goto label_10a658;
            case 0x10A65Cu: goto label_10a65c;
            case 0x10A690u: goto label_10a690;
            case 0x10A694u: goto label_10a694;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x10A5F8u; }
            if (ctx->pc != 0x10A5F8u) { return; }
        }
        }
    }
    ctx->pc = 0x10A5F8u;
label_10a5f8:
    // 0x10a5f8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10a5f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10a5fc:
    // 0x10a5fc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a5fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a600: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10a600u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a604: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x10a604u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10a608: 0x3e00008  jr          $ra
    ctx->pc = 0x10A608u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A60Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A608u;
            // 0x10a60c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A448u: goto label_10a448;
            case 0x10A46Cu: goto label_10a46c;
            case 0x10A488u: goto label_10a488;
            case 0x10A4A8u: goto label_10a4a8;
            case 0x10A4F0u: goto label_10a4f0;
            case 0x10A504u: goto label_10a504;
            case 0x10A514u: goto label_10a514;
            case 0x10A520u: goto label_10a520;
            case 0x10A568u: goto label_10a568;
            case 0x10A57Cu: goto label_10a57c;
            case 0x10A58Cu: goto label_10a58c;
            case 0x10A5A4u: goto label_10a5a4;
            case 0x10A5C8u: goto label_10a5c8;
            case 0x10A5F0u: goto label_10a5f0;
            case 0x10A5F8u: goto label_10a5f8;
            case 0x10A5FCu: goto label_10a5fc;
            case 0x10A648u: goto label_10a648;
            case 0x10A658u: goto label_10a658;
            case 0x10A65Cu: goto label_10a65c;
            case 0x10A690u: goto label_10a690;
            case 0x10A694u: goto label_10a694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A610u;
    // 0x10a610: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10a610u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10a614: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10a614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a618: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a618u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a61c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x10a61cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a620: 0x2e030020  sltiu       $v1, $s0, 0x20
    ctx->pc = 0x10a620u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x10a624: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10a624u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10a628: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x10a628u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x10a62c: 0x10600019  beqz        $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x10A62Cu;
    {
        const bool branch_taken_0x10a62c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A62Cu;
            // 0x10a630: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a62c) {
            ctx->pc = 0x10A694u;
            goto label_10a694;
        }
    }
    ctx->pc = 0x10A634u;
    // 0x10a634: 0x8e2501d4  lw          $a1, 0x1D4($s1)
    ctx->pc = 0x10a634u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 468)));
    // 0x10a638: 0x14a00008  bnez        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x10A638u;
    {
        const bool branch_taken_0x10a638 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A63Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A638u;
            // 0x10a63c: 0x101880  sll         $v1, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a638) {
            ctx->pc = 0x10A65Cu;
            goto label_10a65c;
        }
    }
    ctx->pc = 0x10A640u;
    // 0x10a640: 0xc042912  jal         func_10A448
    ctx->pc = 0x10A640u;
    SET_GPR_U32(ctx, 31, 0x10A648u);
    ctx->pc = 0x10A448u;
    goto label_10a448;
    ctx->pc = 0x10A648u;
label_10a648:
    // 0x10a648: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x10A648u;
    {
        const bool branch_taken_0x10a648 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10a648) {
            ctx->pc = 0x10A64Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A648u;
            // 0x10a64c: 0x8e2501d4  lw          $a1, 0x1D4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 468)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A658u;
            goto label_10a658;
        }
    }
    ctx->pc = 0x10A650u;
    // 0x10a650: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x10A650u;
    {
        const bool branch_taken_0x10a650 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A650u;
            // 0x10a654: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a650) {
            ctx->pc = 0x10A694u;
            goto label_10a694;
        }
    }
    ctx->pc = 0x10A658u;
label_10a658:
    // 0x10a658: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x10a658u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
label_10a65c:
    // 0x10a65c: 0x652021  addu        $a0, $v1, $a1
    ctx->pc = 0x10a65cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x10a660: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x10a660u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10a664: 0x10a0000b  beqz        $a1, . + 4 + (0xB << 2)
    ctx->pc = 0x10A664u;
    {
        const bool branch_taken_0x10a664 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A664u;
            // 0x10a668: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a664) {
            ctx->pc = 0x10A694u;
            goto label_10a694;
        }
    }
    ctx->pc = 0x10A66Cu;
    // 0x10a66c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x10a66cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a670: 0x10a30008  beq         $a1, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x10A670u;
    {
        const bool branch_taken_0x10a670 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x10A674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A670u;
            // 0x10a674: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a670) {
            ctx->pc = 0x10A694u;
            goto label_10a694;
        }
    }
    ctx->pc = 0x10A678u;
    // 0x10a678: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x10a678u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10a67c: 0x10a30005  beq         $a1, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x10A67Cu;
    {
        const bool branch_taken_0x10a67c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x10A680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A67Cu;
            // 0x10a680: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a67c) {
            ctx->pc = 0x10A694u;
            goto label_10a694;
        }
    }
    ctx->pc = 0x10A684u;
    // 0x10a684: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x10a684u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x10a688: 0xa0f809  jalr        $a1
    ctx->pc = 0x10A688u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 5);
        SET_GPR_U32(ctx, 31, 0x10A690u);
        ctx->pc = 0x10A68Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A688u;
            // 0x10a68c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x10A690u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A448u: goto label_10a448;
            case 0x10A46Cu: goto label_10a46c;
            case 0x10A488u: goto label_10a488;
            case 0x10A4A8u: goto label_10a4a8;
            case 0x10A4F0u: goto label_10a4f0;
            case 0x10A504u: goto label_10a504;
            case 0x10A514u: goto label_10a514;
            case 0x10A520u: goto label_10a520;
            case 0x10A568u: goto label_10a568;
            case 0x10A57Cu: goto label_10a57c;
            case 0x10A58Cu: goto label_10a58c;
            case 0x10A5A4u: goto label_10a5a4;
            case 0x10A5C8u: goto label_10a5c8;
            case 0x10A5F0u: goto label_10a5f0;
            case 0x10A5F8u: goto label_10a5f8;
            case 0x10A5FCu: goto label_10a5fc;
            case 0x10A648u: goto label_10a648;
            case 0x10A658u: goto label_10a658;
            case 0x10A65Cu: goto label_10a65c;
            case 0x10A690u: goto label_10a690;
            case 0x10A694u: goto label_10a694;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x10A690u; }
            if (ctx->pc != 0x10A690u) { return; }
        }
        }
    }
    ctx->pc = 0x10A690u;
label_10a690:
    // 0x10a690: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10a690u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10a694:
    // 0x10a694: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a694u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a698: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10a698u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a69c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x10a69cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10a6a0: 0x3e00008  jr          $ra
    ctx->pc = 0x10A6A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A6A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A6A0u;
            // 0x10a6a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A448u: goto label_10a448;
            case 0x10A46Cu: goto label_10a46c;
            case 0x10A488u: goto label_10a488;
            case 0x10A4A8u: goto label_10a4a8;
            case 0x10A4F0u: goto label_10a4f0;
            case 0x10A504u: goto label_10a504;
            case 0x10A514u: goto label_10a514;
            case 0x10A520u: goto label_10a520;
            case 0x10A568u: goto label_10a568;
            case 0x10A57Cu: goto label_10a57c;
            case 0x10A58Cu: goto label_10a58c;
            case 0x10A5A4u: goto label_10a5a4;
            case 0x10A5C8u: goto label_10a5c8;
            case 0x10A5F0u: goto label_10a5f0;
            case 0x10A5F8u: goto label_10a5f8;
            case 0x10A5FCu: goto label_10a5fc;
            case 0x10A648u: goto label_10a648;
            case 0x10A658u: goto label_10a658;
            case 0x10A65Cu: goto label_10a65c;
            case 0x10A690u: goto label_10a690;
            case 0x10A694u: goto label_10a694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A6A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
