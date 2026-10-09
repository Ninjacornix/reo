#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012F780
// Address: 0x12f780 - 0x12f950
void sub_0012F780_0x12f780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012F780_0x12f780");
#endif

    switch (ctx->pc) {
        case 0x12f7b8u: goto label_12f7b8;
        case 0x12f818u: goto label_12f818;
        case 0x12f868u: goto label_12f868;
        case 0x12f8e8u: goto label_12f8e8;
        case 0x12f8f4u: goto label_12f8f4;
        case 0x12f92cu: goto label_12f92c;
        default: break;
    }

    ctx->pc = 0x12f780u;

    // 0x12f780: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12f780u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12f784: 0x3c070022  lui         $a3, 0x22
    ctx->pc = 0x12f784u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)34 << 16));
    // 0x12f788: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12f788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12f78c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x12f78cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f790: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12f790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12f794: 0x24e38760  addiu       $v1, $a3, -0x78A0
    ctx->pc = 0x12f794u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294936416));
    // 0x12f798: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12f798u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12f79c: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x12f79cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f7a0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x12f7a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x12f7a4: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x12f7a4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f7a8: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x12f7a8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12f7ac: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x12F7ACu;
    {
        const bool branch_taken_0x12f7ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12F7B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F7ACu;
            // 0x12f7b0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f7ac) {
            ctx->pc = 0x12F7DCu;
            goto label_12f7dc;
        }
    }
    ctx->pc = 0x12F7B4u;
    // 0x12f7b4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x12f7b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_12f7b8:
    // 0x12f7b8: 0x28a20008  slti        $v0, $a1, 0x8
    ctx->pc = 0x12f7b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x12f7bc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12F7BCu;
    {
        const bool branch_taken_0x12f7bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12F7C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F7BCu;
            // 0x12f7c0: 0x246302f0  addiu       $v1, $v1, 0x2F0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 752));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f7bc) {
            ctx->pc = 0x12F7DCu;
            goto label_12f7dc;
        }
    }
    ctx->pc = 0x12F7C4u;
    // 0x12f7c4: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x12f7c4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12f7c8: 0x0  nop
    ctx->pc = 0x12f7c8u;
    // NOP
    // 0x12f7cc: 0x0  nop
    ctx->pc = 0x12f7ccu;
    // NOP
    // 0x12f7d0: 0x0  nop
    ctx->pc = 0x12f7d0u;
    // NOP
    // 0x12f7d4: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x12F7D4u;
    {
        const bool branch_taken_0x12f7d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12f7d4) {
            ctx->pc = 0x12F7D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12F7D4u;
            // 0x12f7d8: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12F7B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12f7b8;
        }
    }
    ctx->pc = 0x12F7DCu;
label_12f7dc:
    // 0x12f7dc: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x12f7dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x12f7e0: 0x10a30055  beq         $a1, $v1, . + 4 + (0x55 << 2)
    ctx->pc = 0x12F7E0u;
    {
        const bool branch_taken_0x12f7e0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x12F7E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F7E0u;
            // 0x12f7e4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f7e0) {
            ctx->pc = 0x12F938u;
            goto label_12f938;
        }
    }
    ctx->pc = 0x12F7E8u;
    // 0x12f7e8: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x12f7e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x12f7ec: 0x24e38760  addiu       $v1, $a3, -0x78A0
    ctx->pc = 0x12f7ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294936416));
    // 0x12f7f0: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x12f7f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x12f7f4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x12f7f4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f7f8: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x12f7f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x12f7fc: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x12f7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x12f800: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x12f800u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x12f804: 0x438821  addu        $s1, $v0, $v1
    ctx->pc = 0x12f804u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x12f808: 0x1a40000b  blez        $s2, . + 4 + (0xB << 2)
    ctx->pc = 0x12F808u;
    {
        const bool branch_taken_0x12f808 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x12F80Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F808u;
            // 0x12f80c: 0xa2320002  sb          $s2, 0x2($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f808) {
            ctx->pc = 0x12F838u;
            goto label_12f838;
        }
    }
    ctx->pc = 0x12F810u;
    // 0x12f810: 0x26270004  addiu       $a3, $s1, 0x4
    ctx->pc = 0x12f810u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x12f814: 0x0  nop
    ctx->pc = 0x12f814u;
    // NOP
label_12f818:
    // 0x12f818: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x12f818u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x12f81c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x12f81cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x12f820: 0x481821  addu        $v1, $v0, $t0
    ctx->pc = 0x12f820u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x12f824: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x12f824u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x12f828: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x12f828u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12f82c: 0xd2282a  slt         $a1, $a2, $s2
    ctx->pc = 0x12f82cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x12f830: 0x14a0fff9  bnez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x12F830u;
    {
        const bool branch_taken_0x12f830 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x12F834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F830u;
            // 0x12f834: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f830) {
            ctx->pc = 0x12F818u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12f818;
        }
    }
    ctx->pc = 0x12F838u;
label_12f838:
    // 0x12f838: 0x3c107fff  lui         $s0, 0x7FFF
    ctx->pc = 0x12f838u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32767 << 16));
    // 0x12f83c: 0xae29000c  sw          $t1, 0xC($s1)
    ctx->pc = 0x12f83cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 9));
    // 0x12f840: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x12f840u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x12f844: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12f844u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f848: 0xae200028  sw          $zero, 0x28($s1)
    ctx->pc = 0x12f848u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 0));
    // 0x12f84c: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x12f84cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f850: 0xae20002c  sw          $zero, 0x2C($s1)
    ctx->pc = 0x12f850u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 0));
    // 0x12f854: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x12f854u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f858: 0xae200030  sw          $zero, 0x30($s1)
    ctx->pc = 0x12f858u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 48), GPR_U32(ctx, 0));
    // 0x12f85c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x12f85cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f860: 0xc049be0  jal         func_126F80
    ctx->pc = 0x12F860u;
    SET_GPR_U32(ctx, 31, 0x12F868u);
    ctx->pc = 0x12F864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F860u;
            // 0x12f864: 0xae300034  sw          $s0, 0x34($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126F80u;
    if (runtime->hasFunction(0x126F80u)) {
        auto targetFn = runtime->lookupFunction(0x126F80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F868u; }
        if (ctx->pc != 0x12F868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126F80_0x126f80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F868u; }
        if (ctx->pc != 0x12F868u) { return; }
    }
    ctx->pc = 0x12F868u;
label_12f868:
    // 0x12f868: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x12f868u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f86c: 0x24050080  addiu       $a1, $zero, 0x80
    ctx->pc = 0x12f86cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x12f870: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x12f870u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12f874: 0xa3001a  div         $zero, $a1, $v1
    ctx->pc = 0x12f874u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x12f878: 0x3407ac44  ori         $a3, $zero, 0xAC44
    ctx->pc = 0x12f878u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)44100);
    // 0x12f87c: 0x24080012  addiu       $t0, $zero, 0x12
    ctx->pc = 0x12f87cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x12f880: 0x24090004  addiu       $t1, $zero, 0x4
    ctx->pc = 0x12f880u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f884: 0x240a01f4  addiu       $t2, $zero, 0x1F4
    ctx->pc = 0x12f884u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    // 0x12f888: 0x240b0020  addiu       $t3, $zero, 0x20
    ctx->pc = 0x12f888u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x12f88c: 0xae26004c  sw          $a2, 0x4C($s1)
    ctx->pc = 0x12f88cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 76), GPR_U32(ctx, 6));
    // 0x12f890: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x12f890u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x12f894: 0xae27005c  sw          $a3, 0x5C($s1)
    ctx->pc = 0x12f894u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 92), GPR_U32(ctx, 7));
    // 0x12f898: 0xae280050  sw          $t0, 0x50($s1)
    ctx->pc = 0x12f898u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 80), GPR_U32(ctx, 8));
    // 0x12f89c: 0xae230054  sw          $v1, 0x54($s1)
    ctx->pc = 0x12f89cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 84), GPR_U32(ctx, 3));
    // 0x12f8a0: 0xae220048  sw          $v0, 0x48($s1)
    ctx->pc = 0x12f8a0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 2));
    // 0x12f8a4: 0xae320058  sw          $s2, 0x58($s1)
    ctx->pc = 0x12f8a4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 88), GPR_U32(ctx, 18));
    // 0x12f8a8: 0x51200001  beql        $t1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x12F8A8u;
    {
        const bool branch_taken_0x12f8a8 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        if (branch_taken_0x12f8a8) {
            ctx->pc = 0x12F8ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12F8A8u;
            // 0x12f8ac: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x12F8B0u;
            goto label_12f8b0;
        }
    }
    ctx->pc = 0x12F8B0u;
label_12f8b0:
    // 0x12f8b0: 0xae2a0064  sw          $t2, 0x64($s1)
    ctx->pc = 0x12f8b0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 100), GPR_U32(ctx, 10));
    // 0x12f8b4: 0xae300060  sw          $s0, 0x60($s1)
    ctx->pc = 0x12f8b4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 96), GPR_U32(ctx, 16));
    // 0x12f8b8: 0xae200068  sw          $zero, 0x68($s1)
    ctx->pc = 0x12f8b8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 104), GPR_U32(ctx, 0));
    // 0x12f8bc: 0xae20006c  sw          $zero, 0x6C($s1)
    ctx->pc = 0x12f8bcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 108), GPR_U32(ctx, 0));
    // 0x12f8c0: 0xae200070  sw          $zero, 0x70($s1)
    ctx->pc = 0x12f8c0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 112), GPR_U32(ctx, 0));
    // 0x12f8c4: 0xae200074  sw          $zero, 0x74($s1)
    ctx->pc = 0x12f8c4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 116), GPR_U32(ctx, 0));
    // 0x12f8c8: 0xae200078  sw          $zero, 0x78($s1)
    ctx->pc = 0x12f8c8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 120), GPR_U32(ctx, 0));
    // 0x12f8cc: 0xae20007c  sw          $zero, 0x7C($s1)
    ctx->pc = 0x12f8ccu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 124), GPR_U32(ctx, 0));
    // 0x12f8d0: 0xae200038  sw          $zero, 0x38($s1)
    ctx->pc = 0x12f8d0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 56), GPR_U32(ctx, 0));
    // 0x12f8d4: 0xae20003c  sw          $zero, 0x3C($s1)
    ctx->pc = 0x12f8d4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 60), GPR_U32(ctx, 0));
    // 0x12f8d8: 0x2812  mflo        $a1
    ctx->pc = 0x12f8d8u;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x12f8dc: 0xae250044  sw          $a1, 0x44($s1)
    ctx->pc = 0x12f8dcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 68), GPR_U32(ctx, 5));
    // 0x12f8e0: 0xc04b8a0  jal         func_12E280
    ctx->pc = 0x12F8E0u;
    SET_GPR_U32(ctx, 31, 0x12F8E8u);
    ctx->pc = 0x12F8E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F8E0u;
            // 0x12f8e4: 0xae300040  sw          $s0, 0x40($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 64), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E280u;
    if (runtime->hasFunction(0x12E280u)) {
        auto targetFn = runtime->lookupFunction(0x12E280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F8E8u; }
        if (ctx->pc != 0x12F8E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E280_0x12e280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F8E8u; }
        if (ctx->pc != 0x12F8E8u) { return; }
    }
    ctx->pc = 0x12F8E8u;
label_12f8e8:
    // 0x12f8e8: 0x8e240044  lw          $a0, 0x44($s1)
    ctx->pc = 0x12f8e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x12f8ec: 0xc04b8a0  jal         func_12E280
    ctx->pc = 0x12F8ECu;
    SET_GPR_U32(ctx, 31, 0x12F8F4u);
    ctx->pc = 0x12F8F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F8ECu;
            // 0x12f8f0: 0xae220080  sw          $v0, 0x80($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 128), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E280u;
    if (runtime->hasFunction(0x12E280u)) {
        auto targetFn = runtime->lookupFunction(0x12E280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F8F4u; }
        if (ctx->pc != 0x12F8F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E280_0x12e280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F8F4u; }
        if (ctx->pc != 0x12F8F4u) { return; }
    }
    ctx->pc = 0x12F8F4u;
label_12f8f4:
    // 0x12f8f4: 0xa62002cc  sh          $zero, 0x2CC($s1)
    ctx->pc = 0x12f8f4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 716), (uint16_t)GPR_U32(ctx, 0));
    // 0x12f8f8: 0x2403ff80  addiu       $v1, $zero, -0x80
    ctx->pc = 0x12f8f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967168));
    // 0x12f8fc: 0xae220084  sw          $v0, 0x84($s1)
    ctx->pc = 0x12f8fcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 132), GPR_U32(ctx, 2));
    // 0x12f900: 0xa62302ec  sh          $v1, 0x2EC($s1)
    ctx->pc = 0x12f900u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 748), (uint16_t)GPR_U32(ctx, 3));
    // 0x12f904: 0x262402d7  addiu       $a0, $s1, 0x2D7
    ctx->pc = 0x12f904u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 727));
    // 0x12f908: 0xa62302ea  sh          $v1, 0x2EA($s1)
    ctx->pc = 0x12f908u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 746), (uint16_t)GPR_U32(ctx, 3));
    // 0x12f90c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12f90cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f910: 0xa62002c8  sh          $zero, 0x2C8($s1)
    ctx->pc = 0x12f910u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 712), (uint16_t)GPR_U32(ctx, 0));
    // 0x12f914: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x12f914u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12f918: 0xa62002ce  sh          $zero, 0x2CE($s1)
    ctx->pc = 0x12f918u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 718), (uint16_t)GPR_U32(ctx, 0));
    // 0x12f91c: 0xa62002ca  sh          $zero, 0x2CA($s1)
    ctx->pc = 0x12f91cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 714), (uint16_t)GPR_U32(ctx, 0));
    // 0x12f920: 0xa22002d6  sb          $zero, 0x2D6($s1)
    ctx->pc = 0x12f920u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 726), (uint8_t)GPR_U32(ctx, 0));
    // 0x12f924: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x12F924u;
    SET_GPR_U32(ctx, 31, 0x12F92Cu);
    ctx->pc = 0x12F928u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F924u;
            // 0x12f928: 0xa62002e8  sh          $zero, 0x2E8($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 744), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F92Cu; }
        if (ctx->pc != 0x12F92Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F92Cu; }
        if (ctx->pc != 0x12F92Cu) { return; }
    }
    ctx->pc = 0x12F92Cu;
label_12f92c:
    // 0x12f92c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12f92cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f930: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x12f930u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x12f934: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x12f934u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12f938:
    // 0x12f938: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12f938u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12f93c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12f93cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12f940: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12f940u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12f944: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12f944u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12f948: 0x3e00008  jr          $ra
    ctx->pc = 0x12F948u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12F94Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F948u;
            // 0x12f94c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12F7B8u: goto label_12f7b8;
            case 0x12F7DCu: goto label_12f7dc;
            case 0x12F818u: goto label_12f818;
            case 0x12F838u: goto label_12f838;
            case 0x12F868u: goto label_12f868;
            case 0x12F8B0u: goto label_12f8b0;
            case 0x12F8E8u: goto label_12f8e8;
            case 0x12F8F4u: goto label_12f8f4;
            case 0x12F92Cu: goto label_12f92c;
            case 0x12F938u: goto label_12f938;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12F950u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
