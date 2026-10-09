#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001675E8
// Address: 0x1675e8 - 0x167bd8
void sub_001675E8_0x1675e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001675E8_0x1675e8");
#endif

    switch (ctx->pc) {
        case 0x1676e0u: goto label_1676e0;
        case 0x1676f4u: goto label_1676f4;
        case 0x16772cu: goto label_16772c;
        case 0x167888u: goto label_167888;
        case 0x167898u: goto label_167898;
        case 0x1678e8u: goto label_1678e8;
        case 0x1678fcu: goto label_1678fc;
        case 0x167980u: goto label_167980;
        case 0x167994u: goto label_167994;
        case 0x1679ccu: goto label_1679cc;
        case 0x167b30u: goto label_167b30;
        case 0x167b40u: goto label_167b40;
        case 0x167b8cu: goto label_167b8c;
        case 0x167ba0u: goto label_167ba0;
        default: break;
    }

    ctx->pc = 0x1675e8u;

    // 0x1675e8: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x1675e8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1675ec: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1675ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1675f0: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x1675f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1675f4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1675f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1675f8: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1675f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1675fc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1675fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x167600: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167600u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167604: 0x24871140  addiu       $a3, $a0, 0x1140
    ctx->pc = 0x167604u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 4416));
    // 0x167608: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x167608u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16760c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x16760cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167610: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x167610u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x167614: 0xe23821  addu        $a3, $a3, $v0
    ctx->pc = 0x167614u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x167618: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x167618u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x16761c: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x16761Cu;
    {
        const bool branch_taken_0x16761c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16761Cu;
            // 0x167620: 0x34a50401  ori         $a1, $a1, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1025);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16761c) {
            ctx->pc = 0x167630u;
            goto label_167630;
        }
    }
    ctx->pc = 0x167624u;
    // 0x167624: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x167624u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x167628: 0x805a704  j           func_169C10
    ctx->pc = 0x167628u;
    ctx->pc = 0x16762Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167628u;
            // 0x16762c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x167630u;
label_167630:
    // 0x167630: 0x8ce30014  lw          $v1, 0x14($a3)
    ctx->pc = 0x167630u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x167634: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x167634u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167638: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x167638u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16763c: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x16763cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x167640: 0x3e00008  jr          $ra
    ctx->pc = 0x167640u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167640u;
            // 0x167644: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167630u: goto label_167630;
            case 0x167674u: goto label_167674;
            case 0x1676E0u: goto label_1676e0;
            case 0x1676E8u: goto label_1676e8;
            case 0x1676F4u: goto label_1676f4;
            case 0x16772Cu: goto label_16772c;
            case 0x167768u: goto label_167768;
            case 0x167790u: goto label_167790;
            case 0x1677A4u: goto label_1677a4;
            case 0x1677ACu: goto label_1677ac;
            case 0x1677B8u: goto label_1677b8;
            case 0x1677D0u: goto label_1677d0;
            case 0x1677E4u: goto label_1677e4;
            case 0x1677F4u: goto label_1677f4;
            case 0x1677FCu: goto label_1677fc;
            case 0x167888u: goto label_167888;
            case 0x167890u: goto label_167890;
            case 0x167898u: goto label_167898;
            case 0x1678C4u: goto label_1678c4;
            case 0x1678E8u: goto label_1678e8;
            case 0x1678ECu: goto label_1678ec;
            case 0x1678FCu: goto label_1678fc;
            case 0x167900u: goto label_167900;
            case 0x167904u: goto label_167904;
            case 0x167980u: goto label_167980;
            case 0x167988u: goto label_167988;
            case 0x167994u: goto label_167994;
            case 0x1679CCu: goto label_1679cc;
            case 0x167A00u: goto label_167a00;
            case 0x167A2Cu: goto label_167a2c;
            case 0x167A40u: goto label_167a40;
            case 0x167A48u: goto label_167a48;
            case 0x167A58u: goto label_167a58;
            case 0x167A74u: goto label_167a74;
            case 0x167A88u: goto label_167a88;
            case 0x167A9Cu: goto label_167a9c;
            case 0x167AA4u: goto label_167aa4;
            case 0x167B30u: goto label_167b30;
            case 0x167B38u: goto label_167b38;
            case 0x167B40u: goto label_167b40;
            case 0x167B6Cu: goto label_167b6c;
            case 0x167B8Cu: goto label_167b8c;
            case 0x167B90u: goto label_167b90;
            case 0x167BA0u: goto label_167ba0;
            case 0x167BA4u: goto label_167ba4;
            case 0x167BA8u: goto label_167ba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167648u;
    // 0x167648: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167648u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x16764c: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x16764cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167650: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167650u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167654: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167654u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167658: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167658u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x16765c: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x16765cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x167660: 0x24841150  addiu       $a0, $a0, 0x1150
    ctx->pc = 0x167660u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4432));
    // 0x167664: 0x8c820024  lw          $v0, 0x24($a0)
    ctx->pc = 0x167664u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x167668: 0x4400002  bltz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x167668u;
    {
        const bool branch_taken_0x167668 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x16766Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167668u;
            // 0x16766c: 0x461821  addu        $v1, $v0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167668) {
            ctx->pc = 0x167674u;
            goto label_167674;
        }
    }
    ctx->pc = 0x167670u;
    // 0x167670: 0xac830024  sw          $v1, 0x24($a0)
    ctx->pc = 0x167670u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 3));
label_167674:
    // 0x167674: 0x3e00008  jr          $ra
    ctx->pc = 0x167674u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167630u: goto label_167630;
            case 0x167674u: goto label_167674;
            case 0x1676E0u: goto label_1676e0;
            case 0x1676E8u: goto label_1676e8;
            case 0x1676F4u: goto label_1676f4;
            case 0x16772Cu: goto label_16772c;
            case 0x167768u: goto label_167768;
            case 0x167790u: goto label_167790;
            case 0x1677A4u: goto label_1677a4;
            case 0x1677ACu: goto label_1677ac;
            case 0x1677B8u: goto label_1677b8;
            case 0x1677D0u: goto label_1677d0;
            case 0x1677E4u: goto label_1677e4;
            case 0x1677F4u: goto label_1677f4;
            case 0x1677FCu: goto label_1677fc;
            case 0x167888u: goto label_167888;
            case 0x167890u: goto label_167890;
            case 0x167898u: goto label_167898;
            case 0x1678C4u: goto label_1678c4;
            case 0x1678E8u: goto label_1678e8;
            case 0x1678ECu: goto label_1678ec;
            case 0x1678FCu: goto label_1678fc;
            case 0x167900u: goto label_167900;
            case 0x167904u: goto label_167904;
            case 0x167980u: goto label_167980;
            case 0x167988u: goto label_167988;
            case 0x167994u: goto label_167994;
            case 0x1679CCu: goto label_1679cc;
            case 0x167A00u: goto label_167a00;
            case 0x167A2Cu: goto label_167a2c;
            case 0x167A40u: goto label_167a40;
            case 0x167A48u: goto label_167a48;
            case 0x167A58u: goto label_167a58;
            case 0x167A74u: goto label_167a74;
            case 0x167A88u: goto label_167a88;
            case 0x167A9Cu: goto label_167a9c;
            case 0x167AA4u: goto label_167aa4;
            case 0x167B30u: goto label_167b30;
            case 0x167B38u: goto label_167b38;
            case 0x167B40u: goto label_167b40;
            case 0x167B6Cu: goto label_167b6c;
            case 0x167B8Cu: goto label_167b8c;
            case 0x167B90u: goto label_167b90;
            case 0x167BA0u: goto label_167ba0;
            case 0x167BA4u: goto label_167ba4;
            case 0x167BA8u: goto label_167ba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16767Cu;
    // 0x16767c: 0x0  nop
    ctx->pc = 0x16767cu;
    // NOP
    // 0x167680: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167680u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167684: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x167684u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x167688: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167688u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16768c: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x16768cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x167690: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167690u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167694: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x167694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x167698: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16769c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x16769cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x1676a0: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1676a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1676a4: 0x24871140  addiu       $a3, $a0, 0x1140
    ctx->pc = 0x1676a4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 4416));
    // 0x1676a8: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x1676a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x1676ac: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1676acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1676b0: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x1676b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x1676b4: 0xe23821  addu        $a3, $a3, $v0
    ctx->pc = 0x1676b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1676b8: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x1676b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x1676bc: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x1676bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x1676c0: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x1676c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x1676c4: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x1676c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x1676c8: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x1676c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1676cc: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1676CCu;
    {
        const bool branch_taken_0x1676cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1676D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1676CCu;
            // 0x1676d0: 0xc0a82d  daddu       $s5, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1676cc) {
            ctx->pc = 0x1676E8u;
            goto label_1676e8;
        }
    }
    ctx->pc = 0x1676D4u;
    // 0x1676d4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1676d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1676d8: 0xc05a704  jal         func_169C10
    ctx->pc = 0x1676D8u;
    SET_GPR_U32(ctx, 31, 0x1676E0u);
    ctx->pc = 0x1676DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1676D8u;
            // 0x1676dc: 0x34a50401  ori         $a1, $a1, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1025);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1676E0u; }
        if (ctx->pc != 0x1676E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1676E0u; }
        if (ctx->pc != 0x1676E0u) { return; }
    }
    ctx->pc = 0x1676E0u;
label_1676e0:
    // 0x1676e0: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1676E0u;
    {
        const bool branch_taken_0x1676e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1676E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1676E0u;
            // 0x1676e4: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1676e0) {
            ctx->pc = 0x1677FCu;
            goto label_1677fc;
        }
    }
    ctx->pc = 0x1676E8u;
label_1676e8:
    // 0x1676e8: 0x24f00010  addiu       $s0, $a3, 0x10
    ctx->pc = 0x1676e8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
    // 0x1676ec: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x1676ECu;
    SET_GPR_U32(ctx, 31, 0x1676F4u);
    ctx->pc = 0x1676F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1676ECu;
            // 0x1676f0: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1676F4u; }
        if (ctx->pc != 0x1676F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1676F4u; }
        if (ctx->pc != 0x1676F4u) { return; }
    }
    ctx->pc = 0x1676F4u;
label_1676f4:
    // 0x1676f4: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1676f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1676f8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1676f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1676fc: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x1676fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x167700: 0x8e050018  lw          $a1, 0x18($s0)
    ctx->pc = 0x167700u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x167704: 0x8e13002c  lw          $s3, 0x2C($s0)
    ctx->pc = 0x167704u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x167708: 0x8e14001c  lw          $s4, 0x1C($s0)
    ctx->pc = 0x167708u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x16770c: 0x8e110028  lw          $s1, 0x28($s0)
    ctx->pc = 0x16770cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x167710: 0x8e17000c  lw          $s7, 0xC($s0)
    ctx->pc = 0x167710u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x167714: 0x8e120010  lw          $s2, 0x10($s0)
    ctx->pc = 0x167714u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x167718: 0x8e1e0014  lw          $fp, 0x14($s0)
    ctx->pc = 0x167718u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x16771c: 0x8e160020  lw          $s6, 0x20($s0)
    ctx->pc = 0x16771cu;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x167720: 0x7fa50010  sq          $a1, 0x10($sp)
    ctx->pc = 0x167720u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 5));
    // 0x167724: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x167724u;
    SET_GPR_U32(ctx, 31, 0x16772Cu);
    ctx->pc = 0x167728u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167724u;
            // 0x167728: 0x8e100024  lw          $s0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16772Cu; }
        if (ctx->pc != 0x16772Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16772Cu; }
        if (ctx->pc != 0x16772Cu) { return; }
    }
    ctx->pc = 0x16772Cu;
label_16772c:
    // 0x16772c: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x16772cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x167730: 0x2741021  addu        $v0, $s3, $s4
    ctx->pc = 0x167730u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
    // 0x167734: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x167734u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x167738: 0xaeb20008  sw          $s2, 0x8($s5)
    ctx->pc = 0x167738u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 8), GPR_U32(ctx, 18));
    // 0x16773c: 0xaea30000  sw          $v1, 0x0($s5)
    ctx->pc = 0x16773cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
    // 0x167740: 0xaeb70004  sw          $s7, 0x4($s5)
    ctx->pc = 0x167740u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 4), GPR_U32(ctx, 23));
    // 0x167744: 0xaeb10024  sw          $s1, 0x24($s5)
    ctx->pc = 0x167744u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 36), GPR_U32(ctx, 17));
    // 0x167748: 0xaeb30028  sw          $s3, 0x28($s5)
    ctx->pc = 0x167748u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 40), GPR_U32(ctx, 19));
    // 0x16774c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16774Cu;
    {
        const bool branch_taken_0x16774c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x167750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16774Cu;
            // 0x167750: 0x7ba50010  lq          $a1, 0x10($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 5, READ128(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16774c) {
            ctx->pc = 0x167768u;
            goto label_167768;
        }
    }
    ctx->pc = 0x167754u;
    // 0x167754: 0xaea00020  sw          $zero, 0x20($s5)
    ctx->pc = 0x167754u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 0));
    // 0x167758: 0xaea0000c  sw          $zero, 0xC($s5)
    ctx->pc = 0x167758u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 0));
    // 0x16775c: 0xaea00014  sw          $zero, 0x14($s5)
    ctx->pc = 0x16775cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 0));
    // 0x167760: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x167760u;
    {
        const bool branch_taken_0x167760 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x167764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167760u;
            // 0x167764: 0xaea00018  sw          $zero, 0x18($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167760) {
            ctx->pc = 0x1677ACu;
            goto label_1677ac;
        }
    }
    ctx->pc = 0x167768u;
label_167768:
    // 0x167768: 0x2d0102a  slt         $v0, $s6, $s0
    ctx->pc = 0x167768u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x16776c: 0x50400012  beql        $v0, $zero, . + 4 + (0x12 << 2)
    ctx->pc = 0x16776Cu;
    {
        const bool branch_taken_0x16776c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16776c) {
            ctx->pc = 0x167770u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16776Cu;
            // 0x167770: 0x2961023  subu        $v0, $s4, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1677B8u;
            goto label_1677b8;
        }
    }
    ctx->pc = 0x167774u;
    // 0x167774: 0x2161023  subu        $v0, $s0, $s6
    ctx->pc = 0x167774u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 22)));
    // 0x167778: 0x2ae30009  slti        $v1, $s7, 0x9
    ctx->pc = 0x167778u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 23) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x16777c: 0xaea2000c  sw          $v0, 0xC($s5)
    ctx->pc = 0x16777cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
    // 0x167780: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167780u;
    {
        const bool branch_taken_0x167780 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167780u;
            // 0x167784: 0x3d61021  addu        $v0, $fp, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167780) {
            ctx->pc = 0x167790u;
            goto label_167790;
        }
    }
    ctx->pc = 0x167788u;
    // 0x167788: 0x161040  sll         $v0, $s6, 1
    ctx->pc = 0x167788u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
    // 0x16778c: 0x3c21021  addu        $v0, $fp, $v0
    ctx->pc = 0x16778cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
label_167790:
    // 0x167790: 0xaea20014  sw          $v0, 0x14($s5)
    ctx->pc = 0x167790u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 2));
    // 0x167794: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167794u;
    {
        const bool branch_taken_0x167794 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167794u;
            // 0x167798: 0xb61021  addu        $v0, $a1, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167794) {
            ctx->pc = 0x1677A4u;
            goto label_1677a4;
        }
    }
    ctx->pc = 0x16779Cu;
    // 0x16779c: 0x161040  sll         $v0, $s6, 1
    ctx->pc = 0x16779cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
    // 0x1677a0: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1677a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_1677a4:
    // 0x1677a4: 0xaea20018  sw          $v0, 0x18($s5)
    ctx->pc = 0x1677a4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 2));
    // 0x1677a8: 0xaea00020  sw          $zero, 0x20($s5)
    ctx->pc = 0x1677a8u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 0));
label_1677ac:
    // 0x1677ac: 0xaea00010  sw          $zero, 0x10($s5)
    ctx->pc = 0x1677acu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 16), GPR_U32(ctx, 0));
    // 0x1677b0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1677B0u;
    {
        const bool branch_taken_0x1677b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1677B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1677B0u;
            // 0x1677b4: 0xaea0001c  sw          $zero, 0x1C($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1677b0) {
            ctx->pc = 0x1677F4u;
            goto label_1677f4;
        }
    }
    ctx->pc = 0x1677B8u;
label_1677b8:
    // 0x1677b8: 0x2ae30009  slti        $v1, $s7, 0x9
    ctx->pc = 0x1677b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 23) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x1677bc: 0xaea2000c  sw          $v0, 0xC($s5)
    ctx->pc = 0x1677bcu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
    // 0x1677c0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1677C0u;
    {
        const bool branch_taken_0x1677c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1677C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1677C0u;
            // 0x1677c4: 0x3d61021  addu        $v0, $fp, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1677c0) {
            ctx->pc = 0x1677D0u;
            goto label_1677d0;
        }
    }
    ctx->pc = 0x1677C8u;
    // 0x1677c8: 0x161040  sll         $v0, $s6, 1
    ctx->pc = 0x1677c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
    // 0x1677cc: 0x3c21021  addu        $v0, $fp, $v0
    ctx->pc = 0x1677ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
label_1677d0:
    // 0x1677d0: 0xaea20014  sw          $v0, 0x14($s5)
    ctx->pc = 0x1677d0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 2));
    // 0x1677d4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1677D4u;
    {
        const bool branch_taken_0x1677d4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1677D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1677D4u;
            // 0x1677d8: 0xb61021  addu        $v0, $a1, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1677d4) {
            ctx->pc = 0x1677E4u;
            goto label_1677e4;
        }
    }
    ctx->pc = 0x1677DCu;
    // 0x1677dc: 0x161040  sll         $v0, $s6, 1
    ctx->pc = 0x1677dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
    // 0x1677e0: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1677e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_1677e4:
    // 0x1677e4: 0xaea50020  sw          $a1, 0x20($s5)
    ctx->pc = 0x1677e4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 5));
    // 0x1677e8: 0xaea20018  sw          $v0, 0x18($s5)
    ctx->pc = 0x1677e8u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 2));
    // 0x1677ec: 0xaeb00010  sw          $s0, 0x10($s5)
    ctx->pc = 0x1677ecu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 16), GPR_U32(ctx, 16));
    // 0x1677f0: 0xaebe001c  sw          $fp, 0x1C($s5)
    ctx->pc = 0x1677f0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 28), GPR_U32(ctx, 30));
label_1677f4:
    // 0x1677f4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1677f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1677f8: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1677f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1677fc:
    // 0x1677fc: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x1677fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167800: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x167800u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x167804: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x167804u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x167808: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x167808u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16780c: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x16780cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x167810: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x167810u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x167814: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x167814u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x167818: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x167818u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x16781c: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x16781cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x167820: 0x3e00008  jr          $ra
    ctx->pc = 0x167820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167820u;
            // 0x167824: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167630u: goto label_167630;
            case 0x167674u: goto label_167674;
            case 0x1676E0u: goto label_1676e0;
            case 0x1676E8u: goto label_1676e8;
            case 0x1676F4u: goto label_1676f4;
            case 0x16772Cu: goto label_16772c;
            case 0x167768u: goto label_167768;
            case 0x167790u: goto label_167790;
            case 0x1677A4u: goto label_1677a4;
            case 0x1677ACu: goto label_1677ac;
            case 0x1677B8u: goto label_1677b8;
            case 0x1677D0u: goto label_1677d0;
            case 0x1677E4u: goto label_1677e4;
            case 0x1677F4u: goto label_1677f4;
            case 0x1677FCu: goto label_1677fc;
            case 0x167888u: goto label_167888;
            case 0x167890u: goto label_167890;
            case 0x167898u: goto label_167898;
            case 0x1678C4u: goto label_1678c4;
            case 0x1678E8u: goto label_1678e8;
            case 0x1678ECu: goto label_1678ec;
            case 0x1678FCu: goto label_1678fc;
            case 0x167900u: goto label_167900;
            case 0x167904u: goto label_167904;
            case 0x167980u: goto label_167980;
            case 0x167988u: goto label_167988;
            case 0x167994u: goto label_167994;
            case 0x1679CCu: goto label_1679cc;
            case 0x167A00u: goto label_167a00;
            case 0x167A2Cu: goto label_167a2c;
            case 0x167A40u: goto label_167a40;
            case 0x167A48u: goto label_167a48;
            case 0x167A58u: goto label_167a58;
            case 0x167A74u: goto label_167a74;
            case 0x167A88u: goto label_167a88;
            case 0x167A9Cu: goto label_167a9c;
            case 0x167AA4u: goto label_167aa4;
            case 0x167B30u: goto label_167b30;
            case 0x167B38u: goto label_167b38;
            case 0x167B40u: goto label_167b40;
            case 0x167B6Cu: goto label_167b6c;
            case 0x167B8Cu: goto label_167b8c;
            case 0x167B90u: goto label_167b90;
            case 0x167BA0u: goto label_167ba0;
            case 0x167BA4u: goto label_167ba4;
            case 0x167BA8u: goto label_167ba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167828u;
    // 0x167828: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x167828u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x16782c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16782cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x167830: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x167830u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x167834: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x167834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x167838: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x167838u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x16783c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x16783cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167840: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x167840u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x167844: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x167844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x167848: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x167848u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x16784c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x16784cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167850: 0x26461140  addiu       $a2, $s2, 0x1140
    ctx->pc = 0x167850u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 4416));
    // 0x167854: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x167854u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x167858: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x167858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16785c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16785cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167860: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x167860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x167864: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x167864u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167868: 0x12200025  beqz        $s1, . + 4 + (0x25 << 2)
    ctx->pc = 0x167868u;
    {
        const bool branch_taken_0x167868 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x16786Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167868u;
            // 0x16786c: 0xc33021  addu        $a2, $a2, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167868) {
            ctx->pc = 0x167900u;
            goto label_167900;
        }
    }
    ctx->pc = 0x167870u;
    // 0x167870: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x167870u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x167874: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x167874u;
    {
        const bool branch_taken_0x167874 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x167874) {
            ctx->pc = 0x167878u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x167874u;
            // 0x167878: 0x24d00010  addiu       $s0, $a2, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x167890u;
            goto label_167890;
        }
    }
    ctx->pc = 0x16787Cu;
    // 0x16787c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16787cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x167880: 0xc05a704  jal         func_169C10
    ctx->pc = 0x167880u;
    SET_GPR_U32(ctx, 31, 0x167888u);
    ctx->pc = 0x167884u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167880u;
            // 0x167884: 0x34a50401  ori         $a1, $a1, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1025);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167888u; }
        if (ctx->pc != 0x167888u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167888u; }
        if (ctx->pc != 0x167888u) { return; }
    }
    ctx->pc = 0x167888u;
label_167888:
    // 0x167888: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x167888u;
    {
        const bool branch_taken_0x167888 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16788Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167888u;
            // 0x16788c: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167888) {
            ctx->pc = 0x167904u;
            goto label_167904;
        }
    }
    ctx->pc = 0x167890u;
label_167890:
    // 0x167890: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x167890u;
    SET_GPR_U32(ctx, 31, 0x167898u);
    ctx->pc = 0x167894u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167890u;
            // 0x167894: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167898u; }
        if (ctx->pc != 0x167898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167898u; }
        if (ctx->pc != 0x167898u) { return; }
    }
    ctx->pc = 0x167898u;
label_167898:
    // 0x167898: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x167898u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16789c: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x16789cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1678a0: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1678a0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1678a4: 0x8e06001c  lw          $a2, 0x1C($s0)
    ctx->pc = 0x1678a4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1678a8: 0x34a50406  ori         $a1, $a1, 0x406
    ctx->pc = 0x1678a8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1030);
    // 0x1678ac: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1678acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1678b0: 0x46182a  slt         $v1, $v0, $a2
    ctx->pc = 0x1678b0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1678b4: 0x463823  subu        $a3, $v0, $a2
    ctx->pc = 0x1678b4u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1678b8: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1678B8u;
    {
        const bool branch_taken_0x1678b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1678BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1678B8u;
            // 0x1678bc: 0xae020020  sw          $v0, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1678b8) {
            ctx->pc = 0x1678C4u;
            goto label_1678c4;
        }
    }
    ctx->pc = 0x1678C0u;
    // 0x1678c0: 0xae070020  sw          $a3, 0x20($s0)
    ctx->pc = 0x1678c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 7));
label_1678c4:
    // 0x1678c4: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x1678c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1678c8: 0x8e03002c  lw          $v1, 0x2C($s0)
    ctx->pc = 0x1678c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1678cc: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1678ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1678d0: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1678d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1678d4: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x1678d4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1678d8: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1678D8u;
    {
        const bool branch_taken_0x1678d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1678DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1678D8u;
            // 0x1678dc: 0xae020028  sw          $v0, 0x28($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1678d8) {
            ctx->pc = 0x1678ECu;
            goto label_1678ec;
        }
    }
    ctx->pc = 0x1678E0u;
    // 0x1678e0: 0xc05a704  jal         func_169C10
    ctx->pc = 0x1678E0u;
    SET_GPR_U32(ctx, 31, 0x1678E8u);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1678E8u; }
        if (ctx->pc != 0x1678E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1678E8u; }
        if (ctx->pc != 0x1678E8u) { return; }
    }
    ctx->pc = 0x1678E8u;
label_1678e8:
    // 0x1678e8: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1678e8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1678ec:
    // 0x1678ec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1678ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1678f0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1678f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1678f4: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x1678F4u;
    SET_GPR_U32(ctx, 31, 0x1678FCu);
    ctx->pc = 0x1678F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1678F4u;
            // 0x1678f8: 0xae420044  sw          $v0, 0x44($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1678FCu; }
        if (ctx->pc != 0x1678FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1678FCu; }
        if (ctx->pc != 0x1678FCu) { return; }
    }
    ctx->pc = 0x1678FCu;
label_1678fc:
    // 0x1678fc: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x1678fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_167900:
    // 0x167900: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x167900u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_167904:
    // 0x167904: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x167904u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x167908: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x167908u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16790c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16790cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167910: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x167910u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x167914: 0x3e00008  jr          $ra
    ctx->pc = 0x167914u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167914u;
            // 0x167918: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167630u: goto label_167630;
            case 0x167674u: goto label_167674;
            case 0x1676E0u: goto label_1676e0;
            case 0x1676E8u: goto label_1676e8;
            case 0x1676F4u: goto label_1676f4;
            case 0x16772Cu: goto label_16772c;
            case 0x167768u: goto label_167768;
            case 0x167790u: goto label_167790;
            case 0x1677A4u: goto label_1677a4;
            case 0x1677ACu: goto label_1677ac;
            case 0x1677B8u: goto label_1677b8;
            case 0x1677D0u: goto label_1677d0;
            case 0x1677E4u: goto label_1677e4;
            case 0x1677F4u: goto label_1677f4;
            case 0x1677FCu: goto label_1677fc;
            case 0x167888u: goto label_167888;
            case 0x167890u: goto label_167890;
            case 0x167898u: goto label_167898;
            case 0x1678C4u: goto label_1678c4;
            case 0x1678E8u: goto label_1678e8;
            case 0x1678ECu: goto label_1678ec;
            case 0x1678FCu: goto label_1678fc;
            case 0x167900u: goto label_167900;
            case 0x167904u: goto label_167904;
            case 0x167980u: goto label_167980;
            case 0x167988u: goto label_167988;
            case 0x167994u: goto label_167994;
            case 0x1679CCu: goto label_1679cc;
            case 0x167A00u: goto label_167a00;
            case 0x167A2Cu: goto label_167a2c;
            case 0x167A40u: goto label_167a40;
            case 0x167A48u: goto label_167a48;
            case 0x167A58u: goto label_167a58;
            case 0x167A74u: goto label_167a74;
            case 0x167A88u: goto label_167a88;
            case 0x167A9Cu: goto label_167a9c;
            case 0x167AA4u: goto label_167aa4;
            case 0x167B30u: goto label_167b30;
            case 0x167B38u: goto label_167b38;
            case 0x167B40u: goto label_167b40;
            case 0x167B6Cu: goto label_167b6c;
            case 0x167B8Cu: goto label_167b8c;
            case 0x167B90u: goto label_167b90;
            case 0x167BA0u: goto label_167ba0;
            case 0x167BA4u: goto label_167ba4;
            case 0x167BA8u: goto label_167ba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16791Cu;
    // 0x16791c: 0x0  nop
    ctx->pc = 0x16791cu;
    // NOP
    // 0x167920: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167920u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167924: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x167924u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x167928: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167928u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16792c: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x16792cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x167930: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167930u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167934: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x167934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x167938: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16793c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16793cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x167940: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x167940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x167944: 0x24871140  addiu       $a3, $a0, 0x1140
    ctx->pc = 0x167944u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 4416));
    // 0x167948: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x167948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16794c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x16794cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167950: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x167950u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x167954: 0xe23821  addu        $a3, $a3, $v0
    ctx->pc = 0x167954u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x167958: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x167958u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x16795c: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x16795cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x167960: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x167960u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x167964: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x167964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x167968: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x167968u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x16796c: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x16796Cu;
    {
        const bool branch_taken_0x16796c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16796Cu;
            // 0x167970: 0xc0a82d  daddu       $s5, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16796c) {
            ctx->pc = 0x167988u;
            goto label_167988;
        }
    }
    ctx->pc = 0x167974u;
    // 0x167974: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x167974u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x167978: 0xc05a704  jal         func_169C10
    ctx->pc = 0x167978u;
    SET_GPR_U32(ctx, 31, 0x167980u);
    ctx->pc = 0x16797Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167978u;
            // 0x16797c: 0x34a50401  ori         $a1, $a1, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1025);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167980u; }
        if (ctx->pc != 0x167980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167980u; }
        if (ctx->pc != 0x167980u) { return; }
    }
    ctx->pc = 0x167980u;
label_167980:
    // 0x167980: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x167980u;
    {
        const bool branch_taken_0x167980 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x167984u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167980u;
            // 0x167984: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167980) {
            ctx->pc = 0x167AA4u;
            goto label_167aa4;
        }
    }
    ctx->pc = 0x167988u;
label_167988:
    // 0x167988: 0x24f00010  addiu       $s0, $a3, 0x10
    ctx->pc = 0x167988u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
    // 0x16798c: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x16798Cu;
    SET_GPR_U32(ctx, 31, 0x167994u);
    ctx->pc = 0x167990u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16798Cu;
            // 0x167990: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167994u; }
        if (ctx->pc != 0x167994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167994u; }
        if (ctx->pc != 0x167994u) { return; }
    }
    ctx->pc = 0x167994u;
label_167994:
    // 0x167994: 0x8e140008  lw          $s4, 0x8($s0)
    ctx->pc = 0x167994u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x167998: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x167998u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x16799c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x16799cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1679a0: 0x8e13002c  lw          $s3, 0x2C($s0)
    ctx->pc = 0x1679a0u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1679a4: 0x8e110028  lw          $s1, 0x28($s0)
    ctx->pc = 0x1679a4u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1679a8: 0x8e16000c  lw          $s6, 0xC($s0)
    ctx->pc = 0x1679a8u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1679ac: 0x8e120010  lw          $s2, 0x10($s0)
    ctx->pc = 0x1679acu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1679b0: 0x8e170014  lw          $s7, 0x14($s0)
    ctx->pc = 0x1679b0u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1679b4: 0x8e1e0018  lw          $fp, 0x18($s0)
    ctx->pc = 0x1679b4u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1679b8: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x1679b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x1679bc: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1679bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1679c0: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x1679c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x1679c4: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x1679C4u;
    SET_GPR_U32(ctx, 31, 0x1679CCu);
    ctx->pc = 0x1679C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1679C4u;
            // 0x1679c8: 0x8e100024  lw          $s0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1679CCu; }
        if (ctx->pc != 0x1679CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1679CCu; }
        if (ctx->pc != 0x1679CCu) { return; }
    }
    ctx->pc = 0x1679CCu;
label_1679cc:
    // 0x1679cc: 0x271102a  slt         $v0, $s3, $s1
    ctx->pc = 0x1679ccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1679d0: 0xaeb40000  sw          $s4, 0x0($s5)
    ctx->pc = 0x1679d0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 20));
    // 0x1679d4: 0xaeb20008  sw          $s2, 0x8($s5)
    ctx->pc = 0x1679d4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 8), GPR_U32(ctx, 18));
    // 0x1679d8: 0xaeb60004  sw          $s6, 0x4($s5)
    ctx->pc = 0x1679d8u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 4), GPR_U32(ctx, 22));
    // 0x1679dc: 0xaeb10024  sw          $s1, 0x24($s5)
    ctx->pc = 0x1679dcu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 36), GPR_U32(ctx, 17));
    // 0x1679e0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1679E0u;
    {
        const bool branch_taken_0x1679e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1679E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1679E0u;
            // 0x1679e4: 0xaeb30028  sw          $s3, 0x28($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 40), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1679e0) {
            ctx->pc = 0x167A00u;
            goto label_167a00;
        }
    }
    ctx->pc = 0x1679E8u;
    // 0x1679e8: 0xaea00020  sw          $zero, 0x20($s5)
    ctx->pc = 0x1679e8u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 0));
    // 0x1679ec: 0xaea0000c  sw          $zero, 0xC($s5)
    ctx->pc = 0x1679ecu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 0));
    // 0x1679f0: 0xaea00014  sw          $zero, 0x14($s5)
    ctx->pc = 0x1679f0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 0));
    // 0x1679f4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1679F4u;
    {
        const bool branch_taken_0x1679f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1679F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1679F4u;
            // 0x1679f8: 0xaea00018  sw          $zero, 0x18($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1679f4) {
            ctx->pc = 0x167A48u;
            goto label_167a48;
        }
    }
    ctx->pc = 0x1679FCu;
    // 0x1679fc: 0x0  nop
    ctx->pc = 0x1679fcu;
    // NOP
label_167a00:
    // 0x167a00: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x167a00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x167a04: 0x203102a  slt         $v0, $s0, $v1
    ctx->pc = 0x167a04u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x167a08: 0x50400013  beql        $v0, $zero, . + 4 + (0x13 << 2)
    ctx->pc = 0x167A08u;
    {
        const bool branch_taken_0x167a08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x167a08) {
            ctx->pc = 0x167A0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x167A08u;
            // 0x167a0c: 0x8fa30004  lw          $v1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x167A58u;
            goto label_167a58;
        }
    }
    ctx->pc = 0x167A10u;
    // 0x167a10: 0x701023  subu        $v0, $v1, $s0
    ctx->pc = 0x167a10u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x167a14: 0x2ac30009  slti        $v1, $s6, 0x9
    ctx->pc = 0x167a14u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 22) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x167a18: 0xaea2000c  sw          $v0, 0xC($s5)
    ctx->pc = 0x167a18u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
    // 0x167a1c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167A1Cu;
    {
        const bool branch_taken_0x167a1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167A1Cu;
            // 0x167a20: 0x2f01021  addu        $v0, $s7, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167a1c) {
            ctx->pc = 0x167A2Cu;
            goto label_167a2c;
        }
    }
    ctx->pc = 0x167A24u;
    // 0x167a24: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x167a24u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x167a28: 0x2e21021  addu        $v0, $s7, $v0
    ctx->pc = 0x167a28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
label_167a2c:
    // 0x167a2c: 0xaea20014  sw          $v0, 0x14($s5)
    ctx->pc = 0x167a2cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 2));
    // 0x167a30: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167A30u;
    {
        const bool branch_taken_0x167a30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167A34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167A30u;
            // 0x167a34: 0x3d01021  addu        $v0, $fp, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167a30) {
            ctx->pc = 0x167A40u;
            goto label_167a40;
        }
    }
    ctx->pc = 0x167A38u;
    // 0x167a38: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x167a38u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x167a3c: 0x3c21021  addu        $v0, $fp, $v0
    ctx->pc = 0x167a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
label_167a40:
    // 0x167a40: 0xaea20018  sw          $v0, 0x18($s5)
    ctx->pc = 0x167a40u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 2));
    // 0x167a44: 0xaea00020  sw          $zero, 0x20($s5)
    ctx->pc = 0x167a44u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 0));
label_167a48:
    // 0x167a48: 0xaea00010  sw          $zero, 0x10($s5)
    ctx->pc = 0x167a48u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 16), GPR_U32(ctx, 0));
    // 0x167a4c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x167A4Cu;
    {
        const bool branch_taken_0x167a4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x167A50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167A4Cu;
            // 0x167a50: 0xaea0001c  sw          $zero, 0x1C($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167a4c) {
            ctx->pc = 0x167A9Cu;
            goto label_167a9c;
        }
    }
    ctx->pc = 0x167A54u;
    // 0x167a54: 0x0  nop
    ctx->pc = 0x167a54u;
    // NOP
label_167a58:
    // 0x167a58: 0x701023  subu        $v0, $v1, $s0
    ctx->pc = 0x167a58u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x167a5c: 0x2ac30009  slti        $v1, $s6, 0x9
    ctx->pc = 0x167a5cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 22) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x167a60: 0xaea2000c  sw          $v0, 0xC($s5)
    ctx->pc = 0x167a60u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
    // 0x167a64: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167A64u;
    {
        const bool branch_taken_0x167a64 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167A64u;
            // 0x167a68: 0x2f01021  addu        $v0, $s7, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167a64) {
            ctx->pc = 0x167A74u;
            goto label_167a74;
        }
    }
    ctx->pc = 0x167A6Cu;
    // 0x167a6c: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x167a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x167a70: 0x2e21021  addu        $v0, $s7, $v0
    ctx->pc = 0x167a70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
label_167a74:
    // 0x167a74: 0xaea20014  sw          $v0, 0x14($s5)
    ctx->pc = 0x167a74u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 2));
    // 0x167a78: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167A78u;
    {
        const bool branch_taken_0x167a78 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167A78u;
            // 0x167a7c: 0x3d01021  addu        $v0, $fp, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167a78) {
            ctx->pc = 0x167A88u;
            goto label_167a88;
        }
    }
    ctx->pc = 0x167A80u;
    // 0x167a80: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x167a80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x167a84: 0x3c21021  addu        $v0, $fp, $v0
    ctx->pc = 0x167a84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
label_167a88:
    // 0x167a88: 0xaebe0020  sw          $fp, 0x20($s5)
    ctx->pc = 0x167a88u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 30));
    // 0x167a8c: 0xaea20018  sw          $v0, 0x18($s5)
    ctx->pc = 0x167a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 2));
    // 0x167a90: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x167a90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x167a94: 0xaeb7001c  sw          $s7, 0x1C($s5)
    ctx->pc = 0x167a94u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 28), GPR_U32(ctx, 23));
    // 0x167a98: 0xaea20010  sw          $v0, 0x10($s5)
    ctx->pc = 0x167a98u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 16), GPR_U32(ctx, 2));
label_167a9c:
    // 0x167a9c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x167a9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167aa0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x167aa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_167aa4:
    // 0x167aa4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x167aa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x167aa8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x167aa8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x167aac: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x167aacu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167ab0: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x167ab0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x167ab4: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x167ab4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x167ab8: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x167ab8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x167abc: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x167abcu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x167ac0: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x167ac0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x167ac4: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x167ac4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x167ac8: 0x3e00008  jr          $ra
    ctx->pc = 0x167AC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167AC8u;
            // 0x167acc: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167630u: goto label_167630;
            case 0x167674u: goto label_167674;
            case 0x1676E0u: goto label_1676e0;
            case 0x1676E8u: goto label_1676e8;
            case 0x1676F4u: goto label_1676f4;
            case 0x16772Cu: goto label_16772c;
            case 0x167768u: goto label_167768;
            case 0x167790u: goto label_167790;
            case 0x1677A4u: goto label_1677a4;
            case 0x1677ACu: goto label_1677ac;
            case 0x1677B8u: goto label_1677b8;
            case 0x1677D0u: goto label_1677d0;
            case 0x1677E4u: goto label_1677e4;
            case 0x1677F4u: goto label_1677f4;
            case 0x1677FCu: goto label_1677fc;
            case 0x167888u: goto label_167888;
            case 0x167890u: goto label_167890;
            case 0x167898u: goto label_167898;
            case 0x1678C4u: goto label_1678c4;
            case 0x1678E8u: goto label_1678e8;
            case 0x1678ECu: goto label_1678ec;
            case 0x1678FCu: goto label_1678fc;
            case 0x167900u: goto label_167900;
            case 0x167904u: goto label_167904;
            case 0x167980u: goto label_167980;
            case 0x167988u: goto label_167988;
            case 0x167994u: goto label_167994;
            case 0x1679CCu: goto label_1679cc;
            case 0x167A00u: goto label_167a00;
            case 0x167A2Cu: goto label_167a2c;
            case 0x167A40u: goto label_167a40;
            case 0x167A48u: goto label_167a48;
            case 0x167A58u: goto label_167a58;
            case 0x167A74u: goto label_167a74;
            case 0x167A88u: goto label_167a88;
            case 0x167A9Cu: goto label_167a9c;
            case 0x167AA4u: goto label_167aa4;
            case 0x167B30u: goto label_167b30;
            case 0x167B38u: goto label_167b38;
            case 0x167B40u: goto label_167b40;
            case 0x167B6Cu: goto label_167b6c;
            case 0x167B8Cu: goto label_167b8c;
            case 0x167B90u: goto label_167b90;
            case 0x167BA0u: goto label_167ba0;
            case 0x167BA4u: goto label_167ba4;
            case 0x167BA8u: goto label_167ba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167AD0u;
    // 0x167ad0: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x167ad0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167ad4: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x167ad4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x167ad8: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x167ad8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x167adc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x167adcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x167ae0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x167ae0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x167ae4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x167ae4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167ae8: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x167ae8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x167aec: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x167aecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x167af0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x167af0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x167af4: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x167af4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167af8: 0x26461140  addiu       $a2, $s2, 0x1140
    ctx->pc = 0x167af8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 4416));
    // 0x167afc: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x167afcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x167b00: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x167b00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x167b04: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x167b04u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167b08: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x167b08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x167b0c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x167b0cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167b10: 0x12200024  beqz        $s1, . + 4 + (0x24 << 2)
    ctx->pc = 0x167B10u;
    {
        const bool branch_taken_0x167b10 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x167B14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167B10u;
            // 0x167b14: 0xc33021  addu        $a2, $a2, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167b10) {
            ctx->pc = 0x167BA4u;
            goto label_167ba4;
        }
    }
    ctx->pc = 0x167B18u;
    // 0x167b18: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x167b18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x167b1c: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x167B1Cu;
    {
        const bool branch_taken_0x167b1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x167b1c) {
            ctx->pc = 0x167B20u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x167B1Cu;
            // 0x167b20: 0x24d00010  addiu       $s0, $a2, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x167B38u;
            goto label_167b38;
        }
    }
    ctx->pc = 0x167B24u;
    // 0x167b24: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x167b24u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x167b28: 0xc05a704  jal         func_169C10
    ctx->pc = 0x167B28u;
    SET_GPR_U32(ctx, 31, 0x167B30u);
    ctx->pc = 0x167B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167B28u;
            // 0x167b2c: 0x34a50401  ori         $a1, $a1, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1025);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B30u; }
        if (ctx->pc != 0x167B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B30u; }
        if (ctx->pc != 0x167B30u) { return; }
    }
    ctx->pc = 0x167B30u;
label_167b30:
    // 0x167b30: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x167B30u;
    {
        const bool branch_taken_0x167b30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x167B34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167B30u;
            // 0x167b34: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167b30) {
            ctx->pc = 0x167BA8u;
            goto label_167ba8;
        }
    }
    ctx->pc = 0x167B38u;
label_167b38:
    // 0x167b38: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x167B38u;
    SET_GPR_U32(ctx, 31, 0x167B40u);
    ctx->pc = 0x167B3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167B38u;
            // 0x167b3c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B40u; }
        if (ctx->pc != 0x167B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B40u; }
        if (ctx->pc != 0x167B40u) { return; }
    }
    ctx->pc = 0x167B40u;
label_167b40:
    // 0x167b40: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x167b40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167b44: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x167b44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x167b48: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x167b48u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x167b4c: 0x8e03001c  lw          $v1, 0x1C($s0)
    ctx->pc = 0x167b4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x167b50: 0x34a50407  ori         $a1, $a1, 0x407
    ctx->pc = 0x167b50u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1031);
    // 0x167b54: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x167b54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x167b58: 0x433023  subu        $a2, $v0, $v1
    ctx->pc = 0x167b58u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x167b5c: 0x43182a  slt         $v1, $v0, $v1
    ctx->pc = 0x167b5cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x167b60: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x167B60u;
    {
        const bool branch_taken_0x167b60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167B64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167B60u;
            // 0x167b64: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167b60) {
            ctx->pc = 0x167B6Cu;
            goto label_167b6c;
        }
    }
    ctx->pc = 0x167B68u;
    // 0x167b68: 0xae060024  sw          $a2, 0x24($s0)
    ctx->pc = 0x167b68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 6));
label_167b6c:
    // 0x167b6c: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x167b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x167b70: 0x8e030028  lw          $v1, 0x28($s0)
    ctx->pc = 0x167b70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x167b74: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x167b74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x167b78: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x167b78u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x167b7c: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x167B7Cu;
    {
        const bool branch_taken_0x167b7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x167B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167B7Cu;
            // 0x167b80: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167b7c) {
            ctx->pc = 0x167B90u;
            goto label_167b90;
        }
    }
    ctx->pc = 0x167B84u;
    // 0x167b84: 0xc05a704  jal         func_169C10
    ctx->pc = 0x167B84u;
    SET_GPR_U32(ctx, 31, 0x167B8Cu);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B8Cu; }
        if (ctx->pc != 0x167B8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B8Cu; }
        if (ctx->pc != 0x167B8Cu) { return; }
    }
    ctx->pc = 0x167B8Cu;
label_167b8c:
    // 0x167b8c: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x167b8cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_167b90:
    // 0x167b90: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x167b90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x167b94: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x167b94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167b98: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x167B98u;
    SET_GPR_U32(ctx, 31, 0x167BA0u);
    ctx->pc = 0x167B9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167B98u;
            // 0x167b9c: 0xae420044  sw          $v0, 0x44($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167BA0u; }
        if (ctx->pc != 0x167BA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167BA0u; }
        if (ctx->pc != 0x167BA0u) { return; }
    }
    ctx->pc = 0x167BA0u;
label_167ba0:
    // 0x167ba0: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x167ba0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_167ba4:
    // 0x167ba4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x167ba4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_167ba8:
    // 0x167ba8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x167ba8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x167bac: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x167bacu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x167bb0: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x167bb0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167bb4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x167bb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x167bb8: 0x3e00008  jr          $ra
    ctx->pc = 0x167BB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167BB8u;
            // 0x167bbc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167630u: goto label_167630;
            case 0x167674u: goto label_167674;
            case 0x1676E0u: goto label_1676e0;
            case 0x1676E8u: goto label_1676e8;
            case 0x1676F4u: goto label_1676f4;
            case 0x16772Cu: goto label_16772c;
            case 0x167768u: goto label_167768;
            case 0x167790u: goto label_167790;
            case 0x1677A4u: goto label_1677a4;
            case 0x1677ACu: goto label_1677ac;
            case 0x1677B8u: goto label_1677b8;
            case 0x1677D0u: goto label_1677d0;
            case 0x1677E4u: goto label_1677e4;
            case 0x1677F4u: goto label_1677f4;
            case 0x1677FCu: goto label_1677fc;
            case 0x167888u: goto label_167888;
            case 0x167890u: goto label_167890;
            case 0x167898u: goto label_167898;
            case 0x1678C4u: goto label_1678c4;
            case 0x1678E8u: goto label_1678e8;
            case 0x1678ECu: goto label_1678ec;
            case 0x1678FCu: goto label_1678fc;
            case 0x167900u: goto label_167900;
            case 0x167904u: goto label_167904;
            case 0x167980u: goto label_167980;
            case 0x167988u: goto label_167988;
            case 0x167994u: goto label_167994;
            case 0x1679CCu: goto label_1679cc;
            case 0x167A00u: goto label_167a00;
            case 0x167A2Cu: goto label_167a2c;
            case 0x167A40u: goto label_167a40;
            case 0x167A48u: goto label_167a48;
            case 0x167A58u: goto label_167a58;
            case 0x167A74u: goto label_167a74;
            case 0x167A88u: goto label_167a88;
            case 0x167A9Cu: goto label_167a9c;
            case 0x167AA4u: goto label_167aa4;
            case 0x167B30u: goto label_167b30;
            case 0x167B38u: goto label_167b38;
            case 0x167B40u: goto label_167b40;
            case 0x167B6Cu: goto label_167b6c;
            case 0x167B8Cu: goto label_167b8c;
            case 0x167B90u: goto label_167b90;
            case 0x167BA0u: goto label_167ba0;
            case 0x167BA4u: goto label_167ba4;
            case 0x167BA8u: goto label_167ba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167BC0u;
    // 0x167bc0: 0x3e00008  jr          $ra
    ctx->pc = 0x167BC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167BC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167BC0u;
            // 0x167bc4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167630u: goto label_167630;
            case 0x167674u: goto label_167674;
            case 0x1676E0u: goto label_1676e0;
            case 0x1676E8u: goto label_1676e8;
            case 0x1676F4u: goto label_1676f4;
            case 0x16772Cu: goto label_16772c;
            case 0x167768u: goto label_167768;
            case 0x167790u: goto label_167790;
            case 0x1677A4u: goto label_1677a4;
            case 0x1677ACu: goto label_1677ac;
            case 0x1677B8u: goto label_1677b8;
            case 0x1677D0u: goto label_1677d0;
            case 0x1677E4u: goto label_1677e4;
            case 0x1677F4u: goto label_1677f4;
            case 0x1677FCu: goto label_1677fc;
            case 0x167888u: goto label_167888;
            case 0x167890u: goto label_167890;
            case 0x167898u: goto label_167898;
            case 0x1678C4u: goto label_1678c4;
            case 0x1678E8u: goto label_1678e8;
            case 0x1678ECu: goto label_1678ec;
            case 0x1678FCu: goto label_1678fc;
            case 0x167900u: goto label_167900;
            case 0x167904u: goto label_167904;
            case 0x167980u: goto label_167980;
            case 0x167988u: goto label_167988;
            case 0x167994u: goto label_167994;
            case 0x1679CCu: goto label_1679cc;
            case 0x167A00u: goto label_167a00;
            case 0x167A2Cu: goto label_167a2c;
            case 0x167A40u: goto label_167a40;
            case 0x167A48u: goto label_167a48;
            case 0x167A58u: goto label_167a58;
            case 0x167A74u: goto label_167a74;
            case 0x167A88u: goto label_167a88;
            case 0x167A9Cu: goto label_167a9c;
            case 0x167AA4u: goto label_167aa4;
            case 0x167B30u: goto label_167b30;
            case 0x167B38u: goto label_167b38;
            case 0x167B40u: goto label_167b40;
            case 0x167B6Cu: goto label_167b6c;
            case 0x167B8Cu: goto label_167b8c;
            case 0x167B90u: goto label_167b90;
            case 0x167BA0u: goto label_167ba0;
            case 0x167BA4u: goto label_167ba4;
            case 0x167BA8u: goto label_167ba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167BC8u;
    // 0x167bc8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x167bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x167bcc: 0xac820044  sw          $v0, 0x44($a0)
    ctx->pc = 0x167bccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 2));
    // 0x167bd0: 0x3e00008  jr          $ra
    ctx->pc = 0x167BD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167BD0u;
            // 0x167bd4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167630u: goto label_167630;
            case 0x167674u: goto label_167674;
            case 0x1676E0u: goto label_1676e0;
            case 0x1676E8u: goto label_1676e8;
            case 0x1676F4u: goto label_1676f4;
            case 0x16772Cu: goto label_16772c;
            case 0x167768u: goto label_167768;
            case 0x167790u: goto label_167790;
            case 0x1677A4u: goto label_1677a4;
            case 0x1677ACu: goto label_1677ac;
            case 0x1677B8u: goto label_1677b8;
            case 0x1677D0u: goto label_1677d0;
            case 0x1677E4u: goto label_1677e4;
            case 0x1677F4u: goto label_1677f4;
            case 0x1677FCu: goto label_1677fc;
            case 0x167888u: goto label_167888;
            case 0x167890u: goto label_167890;
            case 0x167898u: goto label_167898;
            case 0x1678C4u: goto label_1678c4;
            case 0x1678E8u: goto label_1678e8;
            case 0x1678ECu: goto label_1678ec;
            case 0x1678FCu: goto label_1678fc;
            case 0x167900u: goto label_167900;
            case 0x167904u: goto label_167904;
            case 0x167980u: goto label_167980;
            case 0x167988u: goto label_167988;
            case 0x167994u: goto label_167994;
            case 0x1679CCu: goto label_1679cc;
            case 0x167A00u: goto label_167a00;
            case 0x167A2Cu: goto label_167a2c;
            case 0x167A40u: goto label_167a40;
            case 0x167A48u: goto label_167a48;
            case 0x167A58u: goto label_167a58;
            case 0x167A74u: goto label_167a74;
            case 0x167A88u: goto label_167a88;
            case 0x167A9Cu: goto label_167a9c;
            case 0x167AA4u: goto label_167aa4;
            case 0x167B30u: goto label_167b30;
            case 0x167B38u: goto label_167b38;
            case 0x167B40u: goto label_167b40;
            case 0x167B6Cu: goto label_167b6c;
            case 0x167B8Cu: goto label_167b8c;
            case 0x167B90u: goto label_167b90;
            case 0x167BA0u: goto label_167ba0;
            case 0x167BA4u: goto label_167ba4;
            case 0x167BA8u: goto label_167ba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167BD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
