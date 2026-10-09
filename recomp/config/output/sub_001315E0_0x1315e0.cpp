#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001315E0
// Address: 0x1315e0 - 0x1318c8
void sub_001315E0_0x1315e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001315E0_0x1315e0");
#endif

    switch (ctx->pc) {
        case 0x131630u: goto label_131630;
        case 0x131638u: goto label_131638;
        case 0x1316a8u: goto label_1316a8;
        case 0x131724u: goto label_131724;
        case 0x131738u: goto label_131738;
        case 0x131750u: goto label_131750;
        case 0x131778u: goto label_131778;
        case 0x1317a4u: goto label_1317a4;
        case 0x1317b8u: goto label_1317b8;
        case 0x1317c8u: goto label_1317c8;
        case 0x1317d8u: goto label_1317d8;
        case 0x1317ecu: goto label_1317ec;
        case 0x131850u: goto label_131850;
        default: break;
    }

    ctx->pc = 0x1315e0u;

    // 0x1315e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1315e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1315e4: 0x24a2003f  addiu       $v0, $a1, 0x3F
    ctx->pc = 0x1315e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 63));
    // 0x1315e8: 0x2403ffc0  addiu       $v1, $zero, -0x40
    ctx->pc = 0x1315e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1315ec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1315ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1315f0: 0x438824  and         $s1, $v0, $v1
    ctx->pc = 0x1315f0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1315f4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1315f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1315f8: 0x2251023  subu        $v0, $s1, $a1
    ctx->pc = 0x1315f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
    // 0x1315fc: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1315fcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131600: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x131600u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x131604: 0xc29023  subu        $s2, $a2, $v0
    ctx->pc = 0x131604u;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x131608: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13160c: 0x6600005  bltz        $s3, . + 4 + (0x5 << 2)
    ctx->pc = 0x13160Cu;
    {
        const bool branch_taken_0x13160c = (GPR_S64(ctx, 19) < 0);
        ctx->pc = 0x131610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13160Cu;
            // 0x131610: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13160c) {
            ctx->pc = 0x131624u;
            goto label_131624;
        }
    }
    ctx->pc = 0x131614u;
    // 0x131614: 0x50a00004  beql        $a1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x131614u;
    {
        const bool branch_taken_0x131614 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x131614) {
            ctx->pc = 0x131618u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131614u;
            // 0x131618: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131628u;
            goto label_131628;
        }
    }
    ctx->pc = 0x13161Cu;
    // 0x13161c: 0x4c10006  bgez        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x13161Cu;
    {
        const bool branch_taken_0x13161c = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x131620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13161Cu;
            // 0x131620: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13161c) {
            ctx->pc = 0x131638u;
            goto label_131638;
        }
    }
    ctx->pc = 0x131624u;
label_131624:
    // 0x131624: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x131624u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
label_131628:
    // 0x131628: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x131628u;
    SET_GPR_U32(ctx, 31, 0x131630u);
    ctx->pc = 0x13162Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131628u;
            // 0x13162c: 0x2484aea8  addiu       $a0, $a0, -0x5158 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946472));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131630u; }
        if (ctx->pc != 0x131630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131630u; }
        if (ctx->pc != 0x131630u) { return; }
    }
    ctx->pc = 0x131630u;
label_131630:
    // 0x131630: 0x1000009e  b           . + 4 + (0x9E << 2)
    ctx->pc = 0x131630u;
    {
        const bool branch_taken_0x131630 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x131634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131630u;
            // 0x131634: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131630) {
            ctx->pc = 0x1318ACu;
            goto label_1318ac;
        }
    }
    ctx->pc = 0x131638u;
label_131638:
    // 0x131638: 0x28820010  slti        $v0, $a0, 0x10
    ctx->pc = 0x131638u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13163c: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x13163Cu;
    {
        const bool branch_taken_0x13163c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x131640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13163Cu;
            // 0x131640: 0x24030010  addiu       $v1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13163c) {
            ctx->pc = 0x131670u;
            goto label_131670;
        }
    }
    ctx->pc = 0x131644u;
    // 0x131644: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x131644u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x131648: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x131648u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13164c: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x13164cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x131650: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x131650u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x131654: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x131654u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x131658: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x131658u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x13165c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13165cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x131660: 0x8063f3c8  lb          $v1, -0xC38($v1)
    ctx->pc = 0x131660u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 4294964168)));
    // 0x131664: 0x5460fff4  bnel        $v1, $zero, . + 4 + (-0xC << 2)
    ctx->pc = 0x131664u;
    {
        const bool branch_taken_0x131664 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x131664) {
            ctx->pc = 0x131668u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131664u;
            // 0x131668: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131638u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_131638;
        }
    }
    ctx->pc = 0x13166Cu;
    // 0x13166c: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x13166cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_131670:
    // 0x131670: 0x1083008e  beq         $a0, $v1, . + 4 + (0x8E << 2)
    ctx->pc = 0x131670u;
    {
        const bool branch_taken_0x131670 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x131674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131670u;
            // 0x131674: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131670) {
            ctx->pc = 0x1318ACu;
            goto label_1318ac;
        }
    }
    ctx->pc = 0x131678u;
    // 0x131678: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x131678u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x13167c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13167cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131680: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x131680u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x131684: 0x240600c4  addiu       $a2, $zero, 0xC4
    ctx->pc = 0x131684u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 196));
    // 0x131688: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x131688u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x13168c: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x13168cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x131690: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x131690u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x131694: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x131694u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x131698: 0x2610f3c8  addiu       $s0, $s0, -0xC38
    ctx->pc = 0x131698u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294964168));
    // 0x13169c: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x13169cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1316a0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1316A0u;
    SET_GPR_U32(ctx, 31, 0x1316A8u);
    ctx->pc = 0x1316A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1316A0u;
            // 0x1316a4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1316A8u; }
        if (ctx->pc != 0x1316A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1316A8u; }
        if (ctx->pc != 0x1316A8u) { return; }
    }
    ctx->pc = 0x1316A8u;
label_1316a8:
    // 0x1316a8: 0xa2130003  sb          $s3, 0x3($s0)
    ctx->pc = 0x1316a8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 19));
    // 0x1316ac: 0x131180  sll         $v0, $s3, 6
    ctx->pc = 0x1316acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 6));
    // 0x1316b0: 0x240a0024  addiu       $t2, $zero, 0x24
    ctx->pc = 0x1316b0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x1316b4: 0x531021  addu        $v0, $v0, $s3
    ctx->pc = 0x1316b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1316b8: 0x24082000  addiu       $t0, $zero, 0x2000
    ctx->pc = 0x1316b8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1316bc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1316bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1316c0: 0x24092060  addiu       $t1, $zero, 0x2060
    ctx->pc = 0x1316c0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8288));
    // 0x1316c4: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1316c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1316c8: 0x24060024  addiu       $a2, $zero, 0x24
    ctx->pc = 0x1316c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x1316cc: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x1316ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x1316d0: 0xae11002c  sw          $s1, 0x2C($s0)
    ctx->pc = 0x1316d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 17));
    // 0x1316d4: 0x2422823  subu        $a1, $s2, $v0
    ctx->pc = 0x1316d4u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1316d8: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x1316d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1316dc: 0x24a3fedc  addiu       $v1, $a1, -0x124
    ctx->pc = 0x1316dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967004));
    // 0x1316e0: 0x24a506db  addiu       $a1, $a1, 0x6DB
    ctx->pc = 0x1316e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1755));
    // 0x1316e4: 0x28670000  slti        $a3, $v1, 0x0
    ctx->pc = 0x1316e4u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1316e8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1316e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1316ec: 0xa7180b  movn        $v1, $a1, $a3
    ctx->pc = 0x1316ecu;
    if (GPR_U64(ctx, 7) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 5));
    // 0x1316f0: 0xae020020  sw          $v0, 0x20($s0)
    ctx->pc = 0x1316f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
    // 0x1316f4: 0x31ac3  sra         $v1, $v1, 11
    ctx->pc = 0x1316f4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 11));
    // 0x1316f8: 0xae080030  sw          $t0, 0x30($s0)
    ctx->pc = 0x1316f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 8));
    // 0x1316fc: 0x31ac0  sll         $v1, $v1, 11
    ctx->pc = 0x1316fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x131700: 0xae090034  sw          $t1, 0x34($s0)
    ctx->pc = 0x131700u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 9));
    // 0x131704: 0x6a3821  addu        $a3, $v1, $t2
    ctx->pc = 0x131704u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x131708: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x131708u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13170c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x13170cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x131710: 0xae030024  sw          $v1, 0x24($s0)
    ctx->pc = 0x131710u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 3));
    // 0x131714: 0xae0200b0  sw          $v0, 0xB0($s0)
    ctx->pc = 0x131714u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 176), GPR_U32(ctx, 2));
    // 0x131718: 0xae0a0028  sw          $t2, 0x28($s0)
    ctx->pc = 0x131718u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 10));
    // 0x13171c: 0xc04fe2a  jal         func_13F8A8
    ctx->pc = 0x13171Cu;
    SET_GPR_U32(ctx, 31, 0x131724u);
    ctx->pc = 0x131720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13171Cu;
            // 0x131720: 0xae000014  sw          $zero, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F8A8u;
    if (runtime->hasFunction(0x13F8A8u)) {
        auto targetFn = runtime->lookupFunction(0x13F8A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131724u; }
        if (ctx->pc != 0x131724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F8A8_0x13f8a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131724u; }
        if (ctx->pc != 0x131724u) { return; }
    }
    ctx->pc = 0x131724u;
label_131724:
    // 0x131724: 0x1040002a  beqz        $v0, . + 4 + (0x2A << 2)
    ctx->pc = 0x131724u;
    {
        const bool branch_taken_0x131724 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x131728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131724u;
            // 0x131728: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131724) {
            ctx->pc = 0x1317D0u;
            goto label_1317d0;
        }
    }
    ctx->pc = 0x13172Cu;
    // 0x13172c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x13172cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131730: 0xc04c0f6  jal         func_1303D8
    ctx->pc = 0x131730u;
    SET_GPR_U32(ctx, 31, 0x131738u);
    ctx->pc = 0x131734u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131730u;
            // 0x131734: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1303D8u;
    if (runtime->hasFunction(0x1303D8u)) {
        auto targetFn = runtime->lookupFunction(0x1303D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131738u; }
        if (ctx->pc != 0x131738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001303D8_0x1303d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131738u; }
        if (ctx->pc != 0x131738u) { return; }
    }
    ctx->pc = 0x131738u;
label_131738:
    // 0x131738: 0x10400025  beqz        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x131738u;
    {
        const bool branch_taken_0x131738 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13173Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131738u;
            // 0x13173c: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131738) {
            ctx->pc = 0x1317D0u;
            goto label_1317d0;
        }
    }
    ctx->pc = 0x131740u;
    // 0x131740: 0x1a600013  blez        $s3, . + 4 + (0x13 << 2)
    ctx->pc = 0x131740u;
    {
        const bool branch_taken_0x131740 = (GPR_S64(ctx, 19) <= 0);
        ctx->pc = 0x131744u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131740u;
            // 0x131744: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131740) {
            ctx->pc = 0x131790u;
            goto label_131790;
        }
    }
    ctx->pc = 0x131748u;
    // 0x131748: 0x26120018  addiu       $s2, $s0, 0x18
    ctx->pc = 0x131748u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x13174c: 0x8e060034  lw          $a2, 0x34($s0)
    ctx->pc = 0x13174cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
label_131750:
    // 0x131750: 0x8e050030  lw          $a1, 0x30($s0)
    ctx->pc = 0x131750u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x131754: 0xd12018  mult        $a0, $a2, $s1
    ctx->pc = 0x131754u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x131758: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x131758u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x13175c: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x13175cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x131760: 0xc53023  subu        $a2, $a2, $a1
    ctx->pc = 0x131760u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x131764: 0x63040  sll         $a2, $a2, 1
    ctx->pc = 0x131764u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x131768: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x131768u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x13176c: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x13176cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x131770: 0xc04fe2a  jal         func_13F8A8
    ctx->pc = 0x131770u;
    SET_GPR_U32(ctx, 31, 0x131778u);
    ctx->pc = 0x131774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131770u;
            // 0x131774: 0x442021  addu        $a0, $v0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F8A8u;
    if (runtime->hasFunction(0x13F8A8u)) {
        auto targetFn = runtime->lookupFunction(0x13F8A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131778u; }
        if (ctx->pc != 0x131778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F8A8_0x13f8a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131778u; }
        if (ctx->pc != 0x131778u) { return; }
    }
    ctx->pc = 0x131778u;
label_131778:
    // 0x131778: 0x233182a  slt         $v1, $s1, $s3
    ctx->pc = 0x131778u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x13177c: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x13177cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x131780: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x131780u;
    {
        const bool branch_taken_0x131780 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x131784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131780u;
            // 0x131784: 0x26520004  addiu       $s2, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131780) {
            ctx->pc = 0x1317D0u;
            goto label_1317d0;
        }
    }
    ctx->pc = 0x131788u;
    // 0x131788: 0x5460fff1  bnel        $v1, $zero, . + 4 + (-0xF << 2)
    ctx->pc = 0x131788u;
    {
        const bool branch_taken_0x131788 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x131788) {
            ctx->pc = 0x13178Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131788u;
            // 0x13178c: 0x8e060034  lw          $a2, 0x34($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131750u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_131750;
        }
    }
    ctx->pc = 0x131790u;
label_131790:
    // 0x131790: 0x26110018  addiu       $s1, $s0, 0x18
    ctx->pc = 0x131790u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x131794: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x131794u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x131798: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x131798u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13179c: 0xc04b276  jal         func_12C9D8
    ctx->pc = 0x13179Cu;
    SET_GPR_U32(ctx, 31, 0x1317A4u);
    ctx->pc = 0x1317A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13179Cu;
            // 0x1317a0: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C9D8u;
    if (runtime->hasFunction(0x12C9D8u)) {
        auto targetFn = runtime->lookupFunction(0x12C9D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1317A4u; }
        if (ctx->pc != 0x1317A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C9D8_0x12c9d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1317A4u; }
        if (ctx->pc != 0x1317A4u) { return; }
    }
    ctx->pc = 0x1317A4u;
label_1317a4:
    // 0x1317a4: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1317A4u;
    {
        const bool branch_taken_0x1317a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1317A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1317A4u;
            // 0x1317a8: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1317a4) {
            ctx->pc = 0x1317D0u;
            goto label_1317d0;
        }
    }
    ctx->pc = 0x1317ACu;
    // 0x1317ac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1317acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1317b0: 0xc04b19a  jal         func_12C668
    ctx->pc = 0x1317B0u;
    SET_GPR_U32(ctx, 31, 0x1317B8u);
    ctx->pc = 0x1317B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1317B0u;
            // 0x1317b4: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C668u;
    if (runtime->hasFunction(0x12C668u)) {
        auto targetFn = runtime->lookupFunction(0x12C668u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1317B8u; }
        if (ctx->pc != 0x1317B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C668_0x12c668(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1317B8u; }
        if (ctx->pc != 0x1317B8u) { return; }
    }
    ctx->pc = 0x1317B8u;
label_1317b8:
    // 0x1317b8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1317B8u;
    {
        const bool branch_taken_0x1317b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1317BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1317B8u;
            // 0x1317bc: 0xae02000c  sw          $v0, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1317b8) {
            ctx->pc = 0x1317D0u;
            goto label_1317d0;
        }
    }
    ctx->pc = 0x1317C0u;
    // 0x1317c0: 0xc04f2ec  jal         func_13CBB0
    ctx->pc = 0x1317C0u;
    SET_GPR_U32(ctx, 31, 0x1317C8u);
    ctx->pc = 0x1317C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1317C0u;
            // 0x1317c4: 0x8e040010  lw          $a0, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CBB0u;
    if (runtime->hasFunction(0x13CBB0u)) {
        auto targetFn = runtime->lookupFunction(0x13CBB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1317C8u; }
        if (ctx->pc != 0x1317C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CBB0_0x13cbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1317C8u; }
        if (ctx->pc != 0x1317C8u) { return; }
    }
    ctx->pc = 0x1317C8u;
label_1317c8:
    // 0x1317c8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1317C8u;
    {
        const bool branch_taken_0x1317c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1317CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1317C8u;
            // 0x1317cc: 0xae020094  sw          $v0, 0x94($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1317c8) {
            ctx->pc = 0x1317E0u;
            goto label_1317e0;
        }
    }
    ctx->pc = 0x1317D0u;
label_1317d0:
    // 0x1317d0: 0xc04c646  jal         func_131918
    ctx->pc = 0x1317D0u;
    SET_GPR_U32(ctx, 31, 0x1317D8u);
    ctx->pc = 0x1317D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1317D0u;
            // 0x1317d4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131918u;
    if (runtime->hasFunction(0x131918u)) {
        auto targetFn = runtime->lookupFunction(0x131918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1317D8u; }
        if (ctx->pc != 0x1317D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131918_0x131918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1317D8u; }
        if (ctx->pc != 0x1317D8u) { return; }
    }
    ctx->pc = 0x1317D8u;
label_1317d8:
    // 0x1317d8: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1317D8u;
    {
        const bool branch_taken_0x1317d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1317DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1317D8u;
            // 0x1317dc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1317d8) {
            ctx->pc = 0x1318ACu;
            goto label_1318ac;
        }
    }
    ctx->pc = 0x1317E0u;
label_1317e0:
    // 0x1317e0: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x1317e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1317e4: 0xc04f342  jal         func_13CD08
    ctx->pc = 0x1317E4u;
    SET_GPR_U32(ctx, 31, 0x1317ECu);
    ctx->pc = 0x1317E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1317E4u;
            // 0x1317e8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CD08u;
    if (runtime->hasFunction(0x13CD08u)) {
        auto targetFn = runtime->lookupFunction(0x13CD08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1317ECu; }
        if (ctx->pc != 0x1317ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CD08_0x13cd08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1317ECu; }
        if (ctx->pc != 0x1317ECu) { return; }
    }
    ctx->pc = 0x1317ECu;
label_1317ec:
    // 0x1317ec: 0x3c060022  lui         $a2, 0x22
    ctx->pc = 0x1317ecu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)34 << 16));
    // 0x1317f0: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x1317f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1317f4: 0x3c013f59  lui         $at, 0x3F59
    ctx->pc = 0x1317f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16217 << 16));
    // 0x1317f8: 0x34219999  ori         $at, $at, 0x9999
    ctx->pc = 0x1317f8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)39321);
    // 0x1317fc: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x1317fcu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x131800: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x131800u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x131804: 0x244407ff  addiu       $a0, $v0, 0x7FF
    ctx->pc = 0x131804u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x131808: 0x83100b  movn        $v0, $a0, $v1
    ctx->pc = 0x131808u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x13180c: 0x8cc5b758  lw          $a1, -0x48A8($a2)
    ctx->pc = 0x13180cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4294948696)));
    // 0x131810: 0x212c3  sra         $v0, $v0, 11
    ctx->pc = 0x131810u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
    // 0x131814: 0xa6000040  sh          $zero, 0x40($s0)
    ctx->pc = 0x131814u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 64), (uint16_t)GPR_U32(ctx, 0));
    // 0x131818: 0x21c00  sll         $v1, $v0, 16
    ctx->pc = 0x131818u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x13181c: 0xa602003c  sh          $v0, 0x3C($s0)
    ctx->pc = 0x13181cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 60), (uint16_t)GPR_U32(ctx, 2));
    // 0x131820: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x131820u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x131824: 0xae050038  sw          $a1, 0x38($s0)
    ctx->pc = 0x131824u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 5));
    // 0x131828: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x131828u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x13182c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x13182cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x131830: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x131830u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x131834: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x131834u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x131838: 0x44020800  mfc1        $v0, $f1
    ctx->pc = 0x131838u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x13183c: 0x1a60000b  blez        $s3, . + 4 + (0xB << 2)
    ctx->pc = 0x13183Cu;
    {
        const bool branch_taken_0x13183c = (GPR_S64(ctx, 19) <= 0);
        ctx->pc = 0x131840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13183Cu;
            // 0x131840: 0xa602003e  sh          $v0, 0x3E($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 62), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13183c) {
            ctx->pc = 0x13186Cu;
            goto label_13186c;
        }
    }
    ctx->pc = 0x131844u;
    // 0x131844: 0x260882d  daddu       $s1, $s3, $zero
    ctx->pc = 0x131844u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131848: 0x2403ff80  addiu       $v1, $zero, -0x80
    ctx->pc = 0x131848u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967168));
    // 0x13184c: 0x26020042  addiu       $v0, $s0, 0x42
    ctx->pc = 0x13184cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 66));
label_131850:
    // 0x131850: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x131850u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x131854: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x131854u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x131858: 0x0  nop
    ctx->pc = 0x131858u;
    // NOP
    // 0x13185c: 0x0  nop
    ctx->pc = 0x13185cu;
    // NOP
    // 0x131860: 0x0  nop
    ctx->pc = 0x131860u;
    // NOP
    // 0x131864: 0x1620fffa  bnez        $s1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x131864u;
    {
        const bool branch_taken_0x131864 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x131868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131864u;
            // 0x131868: 0x24420002  addiu       $v0, $v0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131864) {
            ctx->pc = 0x131850u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_131850;
        }
    }
    ctx->pc = 0x13186Cu;
label_13186c:
    // 0x13186c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x13186cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x131870: 0xa6000046  sh          $zero, 0x46($s0)
    ctx->pc = 0x131870u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 70), (uint16_t)GPR_U32(ctx, 0));
    // 0x131874: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x131874u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x131878: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x131878u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13187c: 0xa203006c  sb          $v1, 0x6C($s0)
    ctx->pc = 0x13187cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 108), (uint8_t)GPR_U32(ctx, 3));
    // 0x131880: 0xae000054  sw          $zero, 0x54($s0)
    ctx->pc = 0x131880u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 0));
    // 0x131884: 0xae000058  sw          $zero, 0x58($s0)
    ctx->pc = 0x131884u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 0));
    // 0x131888: 0xae00005c  sw          $zero, 0x5C($s0)
    ctx->pc = 0x131888u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 0));
    // 0x13188c: 0xa6000060  sh          $zero, 0x60($s0)
    ctx->pc = 0x13188cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 0));
    // 0x131890: 0xae000064  sw          $zero, 0x64($s0)
    ctx->pc = 0x131890u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 0));
    // 0x131894: 0xa6000068  sh          $zero, 0x68($s0)
    ctx->pc = 0x131894u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 104), (uint16_t)GPR_U32(ctx, 0));
    // 0x131898: 0xa600006a  sh          $zero, 0x6A($s0)
    ctx->pc = 0x131898u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 106), (uint16_t)GPR_U32(ctx, 0));
    // 0x13189c: 0xa203006d  sb          $v1, 0x6D($s0)
    ctx->pc = 0x13189cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 109), (uint8_t)GPR_U32(ctx, 3));
    // 0x1318a0: 0xa2000072  sb          $zero, 0x72($s0)
    ctx->pc = 0x1318a0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 114), (uint8_t)GPR_U32(ctx, 0));
    // 0x1318a4: 0xae000088  sw          $zero, 0x88($s0)
    ctx->pc = 0x1318a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
    // 0x1318a8: 0xa2000098  sb          $zero, 0x98($s0)
    ctx->pc = 0x1318a8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 152), (uint8_t)GPR_U32(ctx, 0));
label_1318ac:
    // 0x1318ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1318acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1318b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1318b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1318b4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1318b4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1318b8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1318b8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1318bc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1318bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1318c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1318C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1318C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1318C0u;
            // 0x1318c4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131624u: goto label_131624;
            case 0x131628u: goto label_131628;
            case 0x131630u: goto label_131630;
            case 0x131638u: goto label_131638;
            case 0x131670u: goto label_131670;
            case 0x1316A8u: goto label_1316a8;
            case 0x131724u: goto label_131724;
            case 0x131738u: goto label_131738;
            case 0x131750u: goto label_131750;
            case 0x131778u: goto label_131778;
            case 0x131790u: goto label_131790;
            case 0x1317A4u: goto label_1317a4;
            case 0x1317B8u: goto label_1317b8;
            case 0x1317C8u: goto label_1317c8;
            case 0x1317D0u: goto label_1317d0;
            case 0x1317D8u: goto label_1317d8;
            case 0x1317E0u: goto label_1317e0;
            case 0x1317ECu: goto label_1317ec;
            case 0x131850u: goto label_131850;
            case 0x13186Cu: goto label_13186c;
            case 0x1318ACu: goto label_1318ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1318C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
