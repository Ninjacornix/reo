#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001230E0
// Address: 0x1230e0 - 0x123470
void sub_001230E0_0x1230e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001230E0_0x1230e0");
#endif

    switch (ctx->pc) {
        case 0x123210u: goto label_123210;
        default: break;
    }

    ctx->pc = 0x1230e0u;

    // 0x1230e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1230e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1230e4: 0x80c02d  daddu       $t8, $a0, $zero
    ctx->pc = 0x1230e4u;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1230e8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1230e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1230ec: 0x3c104d52  lui         $s0, 0x4D52
    ctx->pc = 0x1230ecu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)19794 << 16));
    // 0x1230f0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1230f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1230f4: 0x3c1100ff  lui         $s1, 0xFF
    ctx->pc = 0x1230f4u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)255 << 16));
    // 0x1230f8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1230f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1230fc: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x1230fcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123100: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x123100u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x123104: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x123104u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123108: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x123108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12310c: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x12310cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123110: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x123110u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x123114: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x123114u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123118: 0x36104f46  ori         $s0, $s0, 0x4F46
    ctx->pc = 0x123118u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)20294);
    // 0x12311c: 0x930f0000  lbu         $t7, 0x0($t8)
    ctx->pc = 0x12311cu;
    SET_GPR_U32(ctx, 15, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x123120: 0x930e0003  lbu         $t6, 0x3($t8)
    ctx->pc = 0x123120u;
    SET_GPR_U32(ctx, 14, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 3)));
    // 0x123124: 0x930c0002  lbu         $t4, 0x2($t8)
    ctx->pc = 0x123124u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 2)));
    // 0x123128: 0x930d0001  lbu         $t5, 0x1($t8)
    ctx->pc = 0x123128u;
    SET_GPR_U32(ctx, 13, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x12312c: 0x27180004  addiu       $t8, $t8, 0x4
    ctx->pc = 0x12312cu;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 4));
    // 0x123130: 0x93050003  lbu         $a1, 0x3($t8)
    ctx->pc = 0x123130u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 3)));
    // 0x123134: 0xe7600  sll         $t6, $t6, 24
    ctx->pc = 0x123134u;
    SET_GPR_S32(ctx, 14, (int32_t)SLL32(GPR_U32(ctx, 14), 24));
    // 0x123138: 0x93030002  lbu         $v1, 0x2($t8)
    ctx->pc = 0x123138u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 2)));
    // 0x12313c: 0xd6a00  sll         $t5, $t5, 8
    ctx->pc = 0x12313cu;
    SET_GPR_S32(ctx, 13, (int32_t)SLL32(GPR_U32(ctx, 13), 8));
    // 0x123140: 0x93040001  lbu         $a0, 0x1($t8)
    ctx->pc = 0x123140u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x123144: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x123144u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x123148: 0x93020000  lbu         $v0, 0x0($t8)
    ctx->pc = 0x123148u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x12314c: 0x27180004  addiu       $t8, $t8, 0x4
    ctx->pc = 0x12314cu;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 4));
    // 0x123150: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x123150u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x123154: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x123154u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x123158: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x123158u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x12315c: 0x93050002  lbu         $a1, 0x2($t8)
    ctx->pc = 0x12315cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 2)));
    // 0x123160: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x123160u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x123164: 0x930b0003  lbu         $t3, 0x3($t8)
    ctx->pc = 0x123164u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 3)));
    // 0x123168: 0x43c825  or          $t9, $v0, $v1
    ctx->pc = 0x123168u;
    SET_GPR_U64(ctx, 25, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x12316c: 0x930a0001  lbu         $t2, 0x1($t8)
    ctx->pc = 0x12316cu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x123170: 0x191a03  sra         $v1, $t9, 8
    ctx->pc = 0x123170u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 25), 8));
    // 0x123174: 0x192602  srl         $a0, $t9, 24
    ctx->pc = 0x123174u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 25), 24));
    // 0x123178: 0x191200  sll         $v0, $t9, 8
    ctx->pc = 0x123178u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 25), 8));
    // 0x12317c: 0x93090000  lbu         $t1, 0x0($t8)
    ctx->pc = 0x12317cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x123180: 0xc6400  sll         $t4, $t4, 16
    ctx->pc = 0x123180u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 16));
    // 0x123184: 0x3063ff00  andi        $v1, $v1, 0xFF00
    ctx->pc = 0x123184u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65280);
    // 0x123188: 0x511024  and         $v0, $v0, $s1
    ctx->pc = 0x123188u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 17));
    // 0x12318c: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x12318cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123190: 0x1ee7825  or          $t7, $t7, $t6
    ctx->pc = 0x123190u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) | GPR_U64(ctx, 14));
    // 0x123194: 0x702d  daddu       $t6, $zero, $zero
    ctx->pc = 0x123194u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123198: 0x18d6025  or          $t4, $t4, $t5
    ctx->pc = 0x123198u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) | GPR_U64(ctx, 13));
    // 0x12319c: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x12319cu;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1231a0: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1231a0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1231a4: 0xb5e00  sll         $t3, $t3, 24
    ctx->pc = 0x1231a4u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 24));
    // 0x1231a8: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x1231a8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x1231ac: 0xa5200  sll         $t2, $t2, 8
    ctx->pc = 0x1231acu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 8));
    // 0x1231b0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1231b0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1231b4: 0x191600  sll         $v0, $t9, 24
    ctx->pc = 0x1231b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 25), 24));
    // 0x1231b8: 0x12b4825  or          $t1, $t1, $t3
    ctx->pc = 0x1231b8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 11));
    // 0x1231bc: 0xaa2825  or          $a1, $a1, $t2
    ctx->pc = 0x1231bcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 10));
    // 0x1231c0: 0x1ec7825  or          $t7, $t7, $t4
    ctx->pc = 0x1231c0u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) | GPR_U64(ctx, 12));
    // 0x1231c4: 0x82c825  or          $t9, $a0, $v0
    ctx->pc = 0x1231c4u;
    SET_GPR_U64(ctx, 25, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1231c8: 0x1254825  or          $t1, $t1, $a1
    ctx->pc = 0x1231c8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 5));
    // 0x1231cc: 0x27180004  addiu       $t8, $t8, 0x4
    ctx->pc = 0x1231ccu;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 4));
    // 0x1231d0: 0x15f0009e  bne         $t7, $s0, . + 4 + (0x9E << 2)
    ctx->pc = 0x1231D0u;
    {
        const bool branch_taken_0x1231d0 = (GPR_U64(ctx, 15) != GPR_U64(ctx, 16));
        ctx->pc = 0x1231D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1231D0u;
            // 0x1231d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1231d0) {
            ctx->pc = 0x12344Cu;
            goto label_12344c;
        }
    }
    ctx->pc = 0x1231D8u;
    // 0x1231d8: 0x3c024646  lui         $v0, 0x4646
    ctx->pc = 0x1231d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17990 << 16));
    // 0x1231dc: 0x34424941  ori         $v0, $v0, 0x4941
    ctx->pc = 0x1231dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)18753);
    // 0x1231e0: 0x51220003  beql        $t1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1231E0u;
    {
        const bool branch_taken_0x1231e0 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 2));
        if (branch_taken_0x1231e0) {
            ctx->pc = 0x1231E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1231E0u;
            // 0x1231e4: 0x3191021  addu        $v0, $t8, $t9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 25)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1231F0u;
            goto label_1231f0;
        }
    }
    ctx->pc = 0x1231E8u;
    // 0x1231e8: 0x10000098  b           . + 4 + (0x98 << 2)
    ctx->pc = 0x1231E8u;
    {
        const bool branch_taken_0x1231e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1231ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1231E8u;
            // 0x1231ec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1231e8) {
            ctx->pc = 0x12344Cu;
            goto label_12344c;
        }
    }
    ctx->pc = 0x1231F0u;
label_1231f0:
    // 0x1231f0: 0x244bfffc  addiu       $t3, $v0, -0x4
    ctx->pc = 0x1231f0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x1231f4: 0x30b182b  sltu        $v1, $t8, $t3
    ctx->pc = 0x1231f4u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 24) < (uint64_t)GPR_U64(ctx, 11)) ? 1 : 0);
    // 0x1231f8: 0x10600094  beqz        $v1, . + 4 + (0x94 << 2)
    ctx->pc = 0x1231F8u;
    {
        const bool branch_taken_0x1231f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1231FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1231F8u;
            // 0x1231fc: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1231f8) {
            ctx->pc = 0x12344Cu;
            goto label_12344c;
        }
    }
    ctx->pc = 0x123200u;
    // 0x123200: 0x3c0c00ff  lui         $t4, 0xFF
    ctx->pc = 0x123200u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)255 << 16));
    // 0x123204: 0x2410ff00  addiu       $s0, $zero, -0x100
    ctx->pc = 0x123204u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x123208: 0x93090000  lbu         $t1, 0x0($t8)
    ctx->pc = 0x123208u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x12320c: 0x0  nop
    ctx->pc = 0x12320cu;
    // NOP
label_123210:
    // 0x123210: 0x3c0a444e  lui         $t2, 0x444E
    ctx->pc = 0x123210u;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)17486 << 16));
    // 0x123214: 0x93080003  lbu         $t0, 0x3($t8)
    ctx->pc = 0x123214u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 3)));
    // 0x123218: 0x354a5353  ori         $t2, $t2, 0x5353
    ctx->pc = 0x123218u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | (uint64_t)(uint16_t)21331);
    // 0x12321c: 0x93060002  lbu         $a2, 0x2($t8)
    ctx->pc = 0x12321cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 2)));
    // 0x123220: 0x93070001  lbu         $a3, 0x1($t8)
    ctx->pc = 0x123220u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x123224: 0x27180004  addiu       $t8, $t8, 0x4
    ctx->pc = 0x123224u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 4));
    // 0x123228: 0x93050003  lbu         $a1, 0x3($t8)
    ctx->pc = 0x123228u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 3)));
    // 0x12322c: 0x84600  sll         $t0, $t0, 24
    ctx->pc = 0x12322cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 24));
    // 0x123230: 0x93030002  lbu         $v1, 0x2($t8)
    ctx->pc = 0x123230u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 2)));
    // 0x123234: 0x63400  sll         $a2, $a2, 16
    ctx->pc = 0x123234u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x123238: 0x93040001  lbu         $a0, 0x1($t8)
    ctx->pc = 0x123238u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x12323c: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x12323cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x123240: 0x93020000  lbu         $v0, 0x0($t8)
    ctx->pc = 0x123240u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x123244: 0x27180004  addiu       $t8, $t8, 0x4
    ctx->pc = 0x123244u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 4));
    // 0x123248: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x123248u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x12324c: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x12324cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x123250: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x123250u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x123254: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x123254u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x123258: 0x43c825  or          $t9, $v0, $v1
    ctx->pc = 0x123258u;
    SET_GPR_U64(ctx, 25, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x12325c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x12325cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x123260: 0x191a03  sra         $v1, $t9, 8
    ctx->pc = 0x123260u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 25), 8));
    // 0x123264: 0x192602  srl         $a0, $t9, 24
    ctx->pc = 0x123264u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 25), 24));
    // 0x123268: 0x191200  sll         $v0, $t9, 8
    ctx->pc = 0x123268u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 25), 8));
    // 0x12326c: 0x3063ff00  andi        $v1, $v1, 0xFF00
    ctx->pc = 0x12326cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65280);
    // 0x123270: 0x4c1024  and         $v0, $v0, $t4
    ctx->pc = 0x123270u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 12));
    // 0x123274: 0x1284825  or          $t1, $t1, $t0
    ctx->pc = 0x123274u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 8));
    // 0x123278: 0xc73025  or          $a2, $a2, $a3
    ctx->pc = 0x123278u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
    // 0x12327c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x12327cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x123280: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x123280u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x123284: 0x191600  sll         $v0, $t9, 24
    ctx->pc = 0x123284u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 25), 24));
    // 0x123288: 0x1267825  or          $t7, $t1, $a2
    ctx->pc = 0x123288u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 9) | GPR_U64(ctx, 6));
    // 0x12328c: 0x11ea004c  beq         $t7, $t2, . + 4 + (0x4C << 2)
    ctx->pc = 0x12328Cu;
    {
        const bool branch_taken_0x12328c = (GPR_U64(ctx, 15) == GPR_U64(ctx, 10));
        ctx->pc = 0x123290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12328Cu;
            // 0x123290: 0x82c825  or          $t9, $a0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 25, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12328c) {
            ctx->pc = 0x1233C0u;
            goto label_1233c0;
        }
    }
    ctx->pc = 0x123294u;
    // 0x123294: 0x3c024d4d  lui         $v0, 0x4D4D
    ctx->pc = 0x123294u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)19789 << 16));
    // 0x123298: 0x34424f43  ori         $v0, $v0, 0x4F43
    ctx->pc = 0x123298u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)20291);
    // 0x12329c: 0x15e20064  bne         $t7, $v0, . + 4 + (0x64 << 2)
    ctx->pc = 0x12329Cu;
    {
        const bool branch_taken_0x12329c = (GPR_U64(ctx, 15) != GPR_U64(ctx, 2));
        ctx->pc = 0x1232A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12329Cu;
            // 0x1232a0: 0x27220001  addiu       $v0, $t9, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 25), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12329c) {
            ctx->pc = 0x123430u;
            goto label_123430;
        }
    }
    ctx->pc = 0x1232A4u;
    // 0x1232a4: 0x15a00066  bnez        $t5, . + 4 + (0x66 << 2)
    ctx->pc = 0x1232A4u;
    {
        const bool branch_taken_0x1232a4 = (GPR_U64(ctx, 13) != GPR_U64(ctx, 0));
        ctx->pc = 0x1232A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1232A4u;
            // 0x1232a8: 0x30b102b  sltu        $v0, $t8, $t3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 24) < (uint64_t)GPR_U64(ctx, 11)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1232a4) {
            ctx->pc = 0x123440u;
            goto label_123440;
        }
    }
    ctx->pc = 0x1232ACu;
    // 0x1232ac: 0x2b220012  slti        $v0, $t9, 0x12
    ctx->pc = 0x1232acu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 25) < (int64_t)(int32_t)18) ? 1 : 0);
    // 0x1232b0: 0x14400066  bnez        $v0, . + 4 + (0x66 << 2)
    ctx->pc = 0x1232B0u;
    {
        const bool branch_taken_0x1232b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1232B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1232B0u;
            // 0x1232b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1232b0) {
            ctx->pc = 0x12344Cu;
            goto label_12344c;
        }
    }
    ctx->pc = 0x1232B8u;
    // 0x1232b8: 0x93040001  lbu         $a0, 0x1($t8)
    ctx->pc = 0x1232b8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x1232bc: 0x2406400e  addiu       $a2, $zero, 0x400E
    ctx->pc = 0x1232bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16398));
    // 0x1232c0: 0x93020000  lbu         $v0, 0x0($t8)
    ctx->pc = 0x1232c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x1232c4: 0x27180002  addiu       $t8, $t8, 0x2
    ctx->pc = 0x1232c4u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 2));
    // 0x1232c8: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x1232c8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1232cc: 0x240d0001  addiu       $t5, $zero, 0x1
    ctx->pc = 0x1232ccu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1232d0: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1232d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x1232d4: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1232d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1232d8: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1232d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1232dc: 0x3063ff00  andi        $v1, $v1, 0xFF00
    ctx->pc = 0x1232dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65280);
    // 0x1232e0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1232e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1232e4: 0xae820000  sw          $v0, 0x0($s4)
    ctx->pc = 0x1232e4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
    // 0x1232e8: 0x93050003  lbu         $a1, 0x3($t8)
    ctx->pc = 0x1232e8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 3)));
    // 0x1232ec: 0x93020002  lbu         $v0, 0x2($t8)
    ctx->pc = 0x1232ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 2)));
    // 0x1232f0: 0x93040001  lbu         $a0, 0x1($t8)
    ctx->pc = 0x1232f0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x1232f4: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x1232f4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x1232f8: 0x93030000  lbu         $v1, 0x0($t8)
    ctx->pc = 0x1232f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x1232fc: 0x27180004  addiu       $t8, $t8, 0x4
    ctx->pc = 0x1232fcu;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 4));
    // 0x123300: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x123300u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x123304: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x123304u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x123308: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x123308u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x12330c: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x12330cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x123310: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x123310u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x123314: 0x32a03  sra         $a1, $v1, 8
    ctx->pc = 0x123314u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 3), 8));
    // 0x123318: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x123318u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x12331c: 0x30a5ff00  andi        $a1, $a1, 0xFF00
    ctx->pc = 0x12331cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x123320: 0x31602  srl         $v0, $v1, 24
    ctx->pc = 0x123320u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 24));
    // 0x123324: 0x8c2024  and         $a0, $a0, $t4
    ctx->pc = 0x123324u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 12));
    // 0x123328: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x123328u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x12332c: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x12332cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x123330: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x123330u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x123334: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x123334u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x123338: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x123338u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x12333c: 0x93040001  lbu         $a0, 0x1($t8)
    ctx->pc = 0x12333cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x123340: 0x93020000  lbu         $v0, 0x0($t8)
    ctx->pc = 0x123340u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x123344: 0x27180002  addiu       $t8, $t8, 0x2
    ctx->pc = 0x123344u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 2));
    // 0x123348: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x123348u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x12334c: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x12334cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x123350: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x123350u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x123354: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x123354u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x123358: 0x3063ff00  andi        $v1, $v1, 0xFF00
    ctx->pc = 0x123358u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65280);
    // 0x12335c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x12335cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x123360: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x123360u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x123364: 0x93050000  lbu         $a1, 0x0($t8)
    ctx->pc = 0x123364u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x123368: 0x93040001  lbu         $a0, 0x1($t8)
    ctx->pc = 0x123368u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x12336c: 0x27180002  addiu       $t8, $t8, 0x2
    ctx->pc = 0x12336cu;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 2));
    // 0x123370: 0x93030001  lbu         $v1, 0x1($t8)
    ctx->pc = 0x123370u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x123374: 0x93020000  lbu         $v0, 0x0($t8)
    ctx->pc = 0x123374u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x123378: 0x27180008  addiu       $t8, $t8, 0x8
    ctx->pc = 0x123378u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 8));
    // 0x12337c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x12337cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x123380: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x123380u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x123384: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x123384u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x123388: 0xa42825  or          $a1, $a1, $a0
    ctx->pc = 0x123388u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x12338c: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x12338cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x123390: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x123390u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x123394: 0x701824  and         $v1, $v1, $s0
    ctx->pc = 0x123394u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 16));
    // 0x123398: 0x52a02  srl         $a1, $a1, 8
    ctx->pc = 0x123398u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 8));
    // 0x12339c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x12339cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1233a0: 0xc53023  subu        $a2, $a2, $a1
    ctx->pc = 0x1233a0u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1233a4: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1233a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1233a8: 0xc21007  srav        $v0, $v0, $a2
    ctx->pc = 0x1233a8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 6) & 0x1F));
    // 0x1233ac: 0x11c00023  beqz        $t6, . + 4 + (0x23 << 2)
    ctx->pc = 0x1233ACu;
    {
        const bool branch_taken_0x1233ac = (GPR_U64(ctx, 14) == GPR_U64(ctx, 0));
        ctx->pc = 0x1233B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1233ACu;
            // 0x1233b0: 0xaea20000  sw          $v0, 0x0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1233ac) {
            ctx->pc = 0x12343Cu;
            goto label_12343c;
        }
    }
    ctx->pc = 0x1233B4u;
    // 0x1233b4: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1233B4u;
    {
        const bool branch_taken_0x1233b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1233B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1233B4u;
            // 0x1233b8: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1233b4) {
            ctx->pc = 0x12344Cu;
            goto label_12344c;
        }
    }
    ctx->pc = 0x1233BCu;
    // 0x1233bc: 0x0  nop
    ctx->pc = 0x1233bcu;
    // NOP
label_1233c0:
    // 0x1233c0: 0x15c0001f  bnez        $t6, . + 4 + (0x1F << 2)
    ctx->pc = 0x1233C0u;
    {
        const bool branch_taken_0x1233c0 = (GPR_U64(ctx, 14) != GPR_U64(ctx, 0));
        ctx->pc = 0x1233C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1233C0u;
            // 0x1233c4: 0x30b102b  sltu        $v0, $t8, $t3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 24) < (uint64_t)GPR_U64(ctx, 11)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1233c0) {
            ctx->pc = 0x123440u;
            goto label_123440;
        }
    }
    ctx->pc = 0x1233C8u;
    // 0x1233c8: 0x93050003  lbu         $a1, 0x3($t8)
    ctx->pc = 0x1233c8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 3)));
    // 0x1233cc: 0x240e0001  addiu       $t6, $zero, 0x1
    ctx->pc = 0x1233ccu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1233d0: 0x93020002  lbu         $v0, 0x2($t8)
    ctx->pc = 0x1233d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 2)));
    // 0x1233d4: 0x93040001  lbu         $a0, 0x1($t8)
    ctx->pc = 0x1233d4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x1233d8: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x1233d8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x1233dc: 0x93030000  lbu         $v1, 0x0($t8)
    ctx->pc = 0x1233dcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x1233e0: 0x27180004  addiu       $t8, $t8, 0x4
    ctx->pc = 0x1233e0u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 4));
    // 0x1233e4: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x1233e4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1233e8: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1233e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1233ec: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x1233ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x1233f0: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1233f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x1233f4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1233f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1233f8: 0x22a02  srl         $a1, $v0, 8
    ctx->pc = 0x1233f8u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1233fc: 0x22200  sll         $a0, $v0, 8
    ctx->pc = 0x1233fcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x123400: 0x21e02  srl         $v1, $v0, 24
    ctx->pc = 0x123400u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x123404: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x123404u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x123408: 0x8c2024  and         $a0, $a0, $t4
    ctx->pc = 0x123408u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 12));
    // 0x12340c: 0x30a5ff00  andi        $a1, $a1, 0xFF00
    ctx->pc = 0x12340cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x123410: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x123410u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x123414: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x123414u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x123418: 0x641025  or          $v0, $v1, $a0
    ctx->pc = 0x123418u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x12341c: 0x11a00007  beqz        $t5, . + 4 + (0x7 << 2)
    ctx->pc = 0x12341Cu;
    {
        const bool branch_taken_0x12341c = (GPR_U64(ctx, 13) == GPR_U64(ctx, 0));
        ctx->pc = 0x123420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12341Cu;
            // 0x123420: 0x3028821  addu        $s1, $t8, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12341c) {
            ctx->pc = 0x12343Cu;
            goto label_12343c;
        }
    }
    ctx->pc = 0x123424u;
    // 0x123424: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x123424u;
    {
        const bool branch_taken_0x123424 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123424u;
            // 0x123428: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123424) {
            ctx->pc = 0x12344Cu;
            goto label_12344c;
        }
    }
    ctx->pc = 0x12342Cu;
    // 0x12342c: 0x0  nop
    ctx->pc = 0x12342cu;
    // NOP
label_123430:
    // 0x123430: 0x2403fffe  addiu       $v1, $zero, -0x2
    ctx->pc = 0x123430u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x123434: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x123434u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x123438: 0x302c021  addu        $t8, $t8, $v0
    ctx->pc = 0x123438u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 2)));
label_12343c:
    // 0x12343c: 0x30b102b  sltu        $v0, $t8, $t3
    ctx->pc = 0x12343cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 24) < (uint64_t)GPR_U64(ctx, 11)) ? 1 : 0);
label_123440:
    // 0x123440: 0x5440ff73  bnel        $v0, $zero, . + 4 + (-0x8D << 2)
    ctx->pc = 0x123440u;
    {
        const bool branch_taken_0x123440 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x123440) {
            ctx->pc = 0x123444u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x123440u;
            // 0x123444: 0x93090000  lbu         $t1, 0x0($t8) (Delay Slot)
        SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x123210u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_123210;
        }
    }
    ctx->pc = 0x123448u;
    // 0x123448: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x123448u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12344c:
    // 0x12344c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12344cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x123450: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x123450u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x123454: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x123454u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x123458: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x123458u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12345c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12345cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x123460: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x123460u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x123464: 0x3e00008  jr          $ra
    ctx->pc = 0x123464u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x123468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123464u;
            // 0x123468: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1231F0u: goto label_1231f0;
            case 0x123210u: goto label_123210;
            case 0x1233C0u: goto label_1233c0;
            case 0x123430u: goto label_123430;
            case 0x12343Cu: goto label_12343c;
            case 0x123440u: goto label_123440;
            case 0x12344Cu: goto label_12344c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12346Cu;
    // 0x12346c: 0x0  nop
    ctx->pc = 0x12346cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
