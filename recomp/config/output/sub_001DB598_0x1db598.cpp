#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DB598
// Address: 0x1db598 - 0x1db914
void sub_001DB598_0x1db598(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DB598_0x1db598");
#endif

    ctx->pc = 0x1db598u;

    // 0x1db598: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1db598u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1db59c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1db59cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1db5a0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1db5a0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db5a4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1db5a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db5a8: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x1db5a8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db5ac: 0xa7c20000  sh          $v0, 0x0($fp)
    ctx->pc = 0x1db5acu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1db5b0: 0xa7c30002  sh          $v1, 0x2($fp)
    ctx->pc = 0x1db5b0u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 2), (uint16_t)GPR_U32(ctx, 3));
    // 0x1db5b4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1db5b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1db5b8: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db5b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1db5bc: 0x97c20000  lhu         $v0, 0x0($fp)
    ctx->pc = 0x1db5bcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db5c0: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1db5c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1db5c4: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db5c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db5c8: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db5c8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db5cc: 0x10400027  beqz        $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x1DB5CCu;
    {
        const bool branch_taken_0x1db5cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db5cc) {
            ctx->pc = 0x1DB66Cu;
            goto label_1db66c;
        }
    }
    ctx->pc = 0x1DB5D4u;
    // 0x1db5d4: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db5d4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db5d8: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1db5d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1db5dc: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db5dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db5e0: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db5e0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db5e4: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DB5E4u;
    {
        const bool branch_taken_0x1db5e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db5e4) {
            ctx->pc = 0x1DB60Cu;
            goto label_1db60c;
        }
    }
    ctx->pc = 0x1DB5ECu;
    // 0x1db5ec: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db5ecu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db5f0: 0x30420020  andi        $v0, $v0, 0x20
    ctx->pc = 0x1db5f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32);
    // 0x1db5f4: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db5f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db5f8: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db5f8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db5fc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB5FCu;
    {
        const bool branch_taken_0x1db5fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db5fc) {
            ctx->pc = 0x1DB60Cu;
            goto label_1db60c;
        }
    }
    ctx->pc = 0x1DB604u;
    // 0x1db604: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB604u;
    {
        const bool branch_taken_0x1db604 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db604) {
            ctx->pc = 0x1DB614u;
            goto label_1db614;
        }
    }
    ctx->pc = 0x1DB60Cu;
label_1db60c:
    // 0x1db60c: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1db60cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1db610: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db610u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1db614:
    // 0x1db614: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db614u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db618: 0x30420002  andi        $v0, $v0, 0x2
    ctx->pc = 0x1db618u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1db61c: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db61cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db620: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db620u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db624: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1DB624u;
    {
        const bool branch_taken_0x1db624 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db624) {
            ctx->pc = 0x1DB664u;
            goto label_1db664;
        }
    }
    ctx->pc = 0x1DB62Cu;
    // 0x1db62c: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db62cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db630: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x1db630u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x1db634: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db634u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db638: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db638u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db63c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DB63Cu;
    {
        const bool branch_taken_0x1db63c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db63c) {
            ctx->pc = 0x1DB664u;
            goto label_1db664;
        }
    }
    ctx->pc = 0x1DB644u;
    // 0x1db644: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db644u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db648: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x1db648u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x1db64c: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db64cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db650: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db650u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db654: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB654u;
    {
        const bool branch_taken_0x1db654 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db654) {
            ctx->pc = 0x1DB664u;
            goto label_1db664;
        }
    }
    ctx->pc = 0x1DB65Cu;
    // 0x1db65c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB65Cu;
    {
        const bool branch_taken_0x1db65c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db65c) {
            ctx->pc = 0x1DB66Cu;
            goto label_1db66c;
        }
    }
    ctx->pc = 0x1DB664u;
label_1db664:
    // 0x1db664: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1db664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1db668: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db668u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1db66c:
    // 0x1db66c: 0x97c20000  lhu         $v0, 0x0($fp)
    ctx->pc = 0x1db66cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db670: 0x30420002  andi        $v0, $v0, 0x2
    ctx->pc = 0x1db670u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1db674: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db674u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db678: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db678u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db67c: 0x10400021  beqz        $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x1DB67Cu;
    {
        const bool branch_taken_0x1db67c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db67c) {
            ctx->pc = 0x1DB704u;
            goto label_1db704;
        }
    }
    ctx->pc = 0x1DB684u;
    // 0x1db684: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db684u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db688: 0x30420002  andi        $v0, $v0, 0x2
    ctx->pc = 0x1db688u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1db68c: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db68cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db690: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db690u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db694: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DB694u;
    {
        const bool branch_taken_0x1db694 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db694) {
            ctx->pc = 0x1DB6BCu;
            goto label_1db6bc;
        }
    }
    ctx->pc = 0x1DB69Cu;
    // 0x1db69c: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db69cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db6a0: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x1db6a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x1db6a4: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db6a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db6a8: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db6a8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db6ac: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB6ACu;
    {
        const bool branch_taken_0x1db6ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db6ac) {
            ctx->pc = 0x1DB6BCu;
            goto label_1db6bc;
        }
    }
    ctx->pc = 0x1DB6B4u;
    // 0x1db6b4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB6B4u;
    {
        const bool branch_taken_0x1db6b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db6b4) {
            ctx->pc = 0x1DB6C4u;
            goto label_1db6c4;
        }
    }
    ctx->pc = 0x1DB6BCu;
label_1db6bc:
    // 0x1db6bc: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1db6bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1db6c0: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db6c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1db6c4:
    // 0x1db6c4: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db6c4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db6c8: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x1db6c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x1db6cc: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db6d0: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db6d0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db6d4: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DB6D4u;
    {
        const bool branch_taken_0x1db6d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db6d4) {
            ctx->pc = 0x1DB6FCu;
            goto label_1db6fc;
        }
    }
    ctx->pc = 0x1DB6DCu;
    // 0x1db6dc: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db6dcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db6e0: 0x30420010  andi        $v0, $v0, 0x10
    ctx->pc = 0x1db6e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16);
    // 0x1db6e4: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db6e8: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db6e8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db6ec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB6ECu;
    {
        const bool branch_taken_0x1db6ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db6ec) {
            ctx->pc = 0x1DB6FCu;
            goto label_1db6fc;
        }
    }
    ctx->pc = 0x1DB6F4u;
    // 0x1db6f4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB6F4u;
    {
        const bool branch_taken_0x1db6f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db6f4) {
            ctx->pc = 0x1DB704u;
            goto label_1db704;
        }
    }
    ctx->pc = 0x1DB6FCu;
label_1db6fc:
    // 0x1db6fc: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1db6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1db700: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db700u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1db704:
    // 0x1db704: 0x97c20000  lhu         $v0, 0x0($fp)
    ctx->pc = 0x1db704u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db708: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x1db708u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x1db70c: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db70cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db710: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db710u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db714: 0x10400021  beqz        $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x1DB714u;
    {
        const bool branch_taken_0x1db714 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db714) {
            ctx->pc = 0x1DB79Cu;
            goto label_1db79c;
        }
    }
    ctx->pc = 0x1DB71Cu;
    // 0x1db71c: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db71cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db720: 0x30420002  andi        $v0, $v0, 0x2
    ctx->pc = 0x1db720u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1db724: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db724u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db728: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db728u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db72c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DB72Cu;
    {
        const bool branch_taken_0x1db72c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db72c) {
            ctx->pc = 0x1DB754u;
            goto label_1db754;
        }
    }
    ctx->pc = 0x1DB734u;
    // 0x1db734: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db734u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db738: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x1db738u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x1db73c: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db73cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db740: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db740u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db744: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB744u;
    {
        const bool branch_taken_0x1db744 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db744) {
            ctx->pc = 0x1DB754u;
            goto label_1db754;
        }
    }
    ctx->pc = 0x1DB74Cu;
    // 0x1db74c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB74Cu;
    {
        const bool branch_taken_0x1db74c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db74c) {
            ctx->pc = 0x1DB75Cu;
            goto label_1db75c;
        }
    }
    ctx->pc = 0x1DB754u;
label_1db754:
    // 0x1db754: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1db754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1db758: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db758u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1db75c:
    // 0x1db75c: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db75cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db760: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x1db760u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x1db764: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db764u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db768: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db768u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db76c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DB76Cu;
    {
        const bool branch_taken_0x1db76c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db76c) {
            ctx->pc = 0x1DB794u;
            goto label_1db794;
        }
    }
    ctx->pc = 0x1DB774u;
    // 0x1db774: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db774u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db778: 0x30420010  andi        $v0, $v0, 0x10
    ctx->pc = 0x1db778u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16);
    // 0x1db77c: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db77cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db780: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db780u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db784: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB784u;
    {
        const bool branch_taken_0x1db784 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db784) {
            ctx->pc = 0x1DB794u;
            goto label_1db794;
        }
    }
    ctx->pc = 0x1DB78Cu;
    // 0x1db78c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB78Cu;
    {
        const bool branch_taken_0x1db78c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db78c) {
            ctx->pc = 0x1DB79Cu;
            goto label_1db79c;
        }
    }
    ctx->pc = 0x1DB794u;
label_1db794:
    // 0x1db794: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1db794u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1db798: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db798u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1db79c:
    // 0x1db79c: 0x97c20000  lhu         $v0, 0x0($fp)
    ctx->pc = 0x1db79cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db7a0: 0x30420020  andi        $v0, $v0, 0x20
    ctx->pc = 0x1db7a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32);
    // 0x1db7a4: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db7a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db7a8: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db7a8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db7ac: 0x10400027  beqz        $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x1DB7ACu;
    {
        const bool branch_taken_0x1db7ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db7ac) {
            ctx->pc = 0x1DB84Cu;
            goto label_1db84c;
        }
    }
    ctx->pc = 0x1DB7B4u;
    // 0x1db7b4: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db7b4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db7b8: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1db7b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1db7bc: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db7bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db7c0: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db7c0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db7c4: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DB7C4u;
    {
        const bool branch_taken_0x1db7c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db7c4) {
            ctx->pc = 0x1DB7ECu;
            goto label_1db7ec;
        }
    }
    ctx->pc = 0x1DB7CCu;
    // 0x1db7cc: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db7ccu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db7d0: 0x30420020  andi        $v0, $v0, 0x20
    ctx->pc = 0x1db7d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32);
    // 0x1db7d4: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db7d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db7d8: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db7d8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db7dc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB7DCu;
    {
        const bool branch_taken_0x1db7dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db7dc) {
            ctx->pc = 0x1DB7ECu;
            goto label_1db7ec;
        }
    }
    ctx->pc = 0x1DB7E4u;
    // 0x1db7e4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB7E4u;
    {
        const bool branch_taken_0x1db7e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db7e4) {
            ctx->pc = 0x1DB7F4u;
            goto label_1db7f4;
        }
    }
    ctx->pc = 0x1DB7ECu;
label_1db7ec:
    // 0x1db7ec: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1db7ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1db7f0: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db7f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1db7f4:
    // 0x1db7f4: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db7f4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db7f8: 0x30420002  andi        $v0, $v0, 0x2
    ctx->pc = 0x1db7f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1db7fc: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db800: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db800u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db804: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1DB804u;
    {
        const bool branch_taken_0x1db804 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db804) {
            ctx->pc = 0x1DB844u;
            goto label_1db844;
        }
    }
    ctx->pc = 0x1DB80Cu;
    // 0x1db80c: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db80cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db810: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x1db810u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x1db814: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db814u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db818: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db818u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db81c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DB81Cu;
    {
        const bool branch_taken_0x1db81c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db81c) {
            ctx->pc = 0x1DB844u;
            goto label_1db844;
        }
    }
    ctx->pc = 0x1DB824u;
    // 0x1db824: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db824u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db828: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x1db828u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x1db82c: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db82cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db830: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db830u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db834: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB834u;
    {
        const bool branch_taken_0x1db834 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db834) {
            ctx->pc = 0x1DB844u;
            goto label_1db844;
        }
    }
    ctx->pc = 0x1DB83Cu;
    // 0x1db83c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB83Cu;
    {
        const bool branch_taken_0x1db83c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db83c) {
            ctx->pc = 0x1DB84Cu;
            goto label_1db84c;
        }
    }
    ctx->pc = 0x1DB844u;
label_1db844:
    // 0x1db844: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1db844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1db848: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db848u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1db84c:
    // 0x1db84c: 0x97c20000  lhu         $v0, 0x0($fp)
    ctx->pc = 0x1db84cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db850: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x1db850u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x1db854: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db854u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db858: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db858u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db85c: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1DB85Cu;
    {
        const bool branch_taken_0x1db85c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db85c) {
            ctx->pc = 0x1DB8A4u;
            goto label_1db8a4;
        }
    }
    ctx->pc = 0x1DB864u;
    // 0x1db864: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db864u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db868: 0x30420002  andi        $v0, $v0, 0x2
    ctx->pc = 0x1db868u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1db86c: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db86cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db870: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db870u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db874: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DB874u;
    {
        const bool branch_taken_0x1db874 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db874) {
            ctx->pc = 0x1DB89Cu;
            goto label_1db89c;
        }
    }
    ctx->pc = 0x1DB87Cu;
    // 0x1db87c: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db87cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db880: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x1db880u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x1db884: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db884u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db888: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db888u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db88c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB88Cu;
    {
        const bool branch_taken_0x1db88c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db88c) {
            ctx->pc = 0x1DB89Cu;
            goto label_1db89c;
        }
    }
    ctx->pc = 0x1DB894u;
    // 0x1db894: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB894u;
    {
        const bool branch_taken_0x1db894 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db894) {
            ctx->pc = 0x1DB8A4u;
            goto label_1db8a4;
        }
    }
    ctx->pc = 0x1DB89Cu;
label_1db89c:
    // 0x1db89c: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1db89cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1db8a0: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db8a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1db8a4:
    // 0x1db8a4: 0x97c20000  lhu         $v0, 0x0($fp)
    ctx->pc = 0x1db8a4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db8a8: 0x30420010  andi        $v0, $v0, 0x10
    ctx->pc = 0x1db8a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16);
    // 0x1db8ac: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db8acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db8b0: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db8b0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db8b4: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1DB8B4u;
    {
        const bool branch_taken_0x1db8b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db8b4) {
            ctx->pc = 0x1DB8FCu;
            goto label_1db8fc;
        }
    }
    ctx->pc = 0x1DB8BCu;
    // 0x1db8bc: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db8bcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db8c0: 0x30420002  andi        $v0, $v0, 0x2
    ctx->pc = 0x1db8c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1db8c4: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db8c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db8c8: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db8c8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db8cc: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DB8CCu;
    {
        const bool branch_taken_0x1db8cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db8cc) {
            ctx->pc = 0x1DB8F4u;
            goto label_1db8f4;
        }
    }
    ctx->pc = 0x1DB8D4u;
    // 0x1db8d4: 0x97c20002  lhu         $v0, 0x2($fp)
    ctx->pc = 0x1db8d4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1db8d8: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x1db8d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x1db8dc: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1db8dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1db8e0: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1db8e0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1db8e4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB8E4u;
    {
        const bool branch_taken_0x1db8e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db8e4) {
            ctx->pc = 0x1DB8F4u;
            goto label_1db8f4;
        }
    }
    ctx->pc = 0x1DB8ECu;
    // 0x1db8ec: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB8ECu;
    {
        const bool branch_taken_0x1db8ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db8ec) {
            ctx->pc = 0x1DB8FCu;
            goto label_1db8fc;
        }
    }
    ctx->pc = 0x1DB8F4u;
label_1db8f4:
    // 0x1db8f4: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1db8f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1db8f8: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db8f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1db8fc:
    // 0x1db8fc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1db8fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db900: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1db900u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db904: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1db904u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1db908: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1db908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1db90c: 0x3e00008  jr          $ra
    ctx->pc = 0x1DB90Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DB60Cu: goto label_1db60c;
            case 0x1DB614u: goto label_1db614;
            case 0x1DB664u: goto label_1db664;
            case 0x1DB66Cu: goto label_1db66c;
            case 0x1DB6BCu: goto label_1db6bc;
            case 0x1DB6C4u: goto label_1db6c4;
            case 0x1DB6FCu: goto label_1db6fc;
            case 0x1DB704u: goto label_1db704;
            case 0x1DB754u: goto label_1db754;
            case 0x1DB75Cu: goto label_1db75c;
            case 0x1DB794u: goto label_1db794;
            case 0x1DB79Cu: goto label_1db79c;
            case 0x1DB7ECu: goto label_1db7ec;
            case 0x1DB7F4u: goto label_1db7f4;
            case 0x1DB844u: goto label_1db844;
            case 0x1DB84Cu: goto label_1db84c;
            case 0x1DB89Cu: goto label_1db89c;
            case 0x1DB8A4u: goto label_1db8a4;
            case 0x1DB8F4u: goto label_1db8f4;
            case 0x1DB8FCu: goto label_1db8fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DB914u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
