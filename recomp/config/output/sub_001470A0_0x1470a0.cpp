#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001470A0
// Address: 0x1470a0 - 0x147210
void sub_001470A0_0x1470a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001470A0_0x1470a0");
#endif

    switch (ctx->pc) {
        case 0x147100u: goto label_147100;
        case 0x14718cu: goto label_14718c;
        default: break;
    }

    ctx->pc = 0x1470a0u;

    // 0x1470a0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1470a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1470a4: 0x24050140  addiu       $a1, $zero, 0x140
    ctx->pc = 0x1470a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x1470a8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1470a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1470ac: 0x3c020fff  lui         $v0, 0xFFF
    ctx->pc = 0x1470acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
    // 0x1470b0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1470b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1470b4: 0x3c120026  lui         $s2, 0x26
    ctx->pc = 0x1470b4u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)38 << 16));
    // 0x1470b8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1470b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1470bc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1470bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1470c0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1470c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1470c4: 0x26444a00  addiu       $a0, $s2, 0x4A00
    ctx->pc = 0x1470c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 18944));
    // 0x1470c8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1470c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1470cc: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x1470ccu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1470d0: 0x8e180828  lw          $t8, 0x828($s0)
    ctx->pc = 0x1470d0u;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x1470d4: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x1470d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1470d8: 0x3051818  mult        $v1, $t8, $a1
    ctx->pc = 0x1470d8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 24) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1470dc: 0x702821  addu        $a1, $v1, $s0
    ctx->pc = 0x1470dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1470e0: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x1470e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x1470e4: 0x8cac06d4  lw          $t4, 0x6D4($a1)
    ctx->pc = 0x1470e4u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 1748)));
    // 0x1470e8: 0x19800025  blez        $t4, . + 4 + (0x25 << 2)
    ctx->pc = 0x1470E8u;
    {
        const bool branch_taken_0x1470e8 = (GPR_S64(ctx, 12) <= 0);
        ctx->pc = 0x1470ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1470E8u;
            // 0x1470ec: 0x835025  or          $t2, $a0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1470e8) {
            ctx->pc = 0x147180u;
            goto label_147180;
        }
    }
    ctx->pc = 0x1470F0u;
    // 0x1470f0: 0x260f05b0  addiu       $t7, $s0, 0x5B0
    ctx->pc = 0x1470f0u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 16), 1456));
    // 0x1470f4: 0x260e05c0  addiu       $t6, $s0, 0x5C0
    ctx->pc = 0x1470f4u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 16), 1472));
    // 0x1470f8: 0x258dffff  addiu       $t5, $t4, -0x1
    ctx->pc = 0x1470f8u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967295));
    // 0x1470fc: 0x261105a8  addiu       $s1, $s0, 0x5A8
    ctx->pc = 0x1470fcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 1448));
label_147100:
    // 0x147100: 0x24030140  addiu       $v1, $zero, 0x140
    ctx->pc = 0x147100u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x147104: 0x16d1026  xor         $v0, $t3, $t5
    ctx->pc = 0x147104u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 11) ^ GPR_U64(ctx, 13));
    // 0x147108: 0x3031818  mult        $v1, $t8, $v1
    ctx->pc = 0x147108u;
    { int64_t result = (int64_t)GPR_S32(ctx, 24) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x14710c: 0xb2080  sll         $a0, $t3, 2
    ctx->pc = 0x14710cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 11), 2));
    // 0x147110: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x147110u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x147114: 0x3c060fff  lui         $a2, 0xFFF
    ctx->pc = 0x147114u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4095 << 16));
    // 0x147118: 0x2280a  movz        $a1, $zero, $v0
    ctx->pc = 0x147118u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 0));
    // 0x14711c: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x14711cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x147120: 0x52f38  dsll        $a1, $a1, 28
    ctx->pc = 0x147120u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 28);
    // 0x147124: 0x3c093000  lui         $t1, 0x3000
    ctx->pc = 0x147124u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)12288 << 16));
    // 0x147128: 0x35290030  ori         $t1, $t1, 0x30
    ctx->pc = 0x147128u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)48);
    // 0x14712c: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x14712cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x147130: 0x24080030  addiu       $t0, $zero, 0x30
    ctx->pc = 0x147130u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x147134: 0x1c41021  addu        $v0, $t6, $a0
    ctx->pc = 0x147134u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 4)));
    // 0x147138: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x147138u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x14713c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14713cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x147140: 0x1e42021  addu        $a0, $t7, $a0
    ctx->pc = 0x147140u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 15), GPR_U32(ctx, 4)));
    // 0x147144: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x147144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x147148: 0x16c382a  slt         $a3, $t3, $t4
    ctx->pc = 0x147148u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 11) < (int64_t)GPR_S64(ctx, 12)) ? 1 : 0);
    // 0x14714c: 0x661824  and         $v1, $v1, $a2
    ctx->pc = 0x14714cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 6));
    // 0x147150: 0x461024  and         $v0, $v0, $a2
    ctx->pc = 0x147150u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 6));
    // 0x147154: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x147154u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x147158: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x147158u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x14715c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x14715cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x147160: 0x491025  or          $v0, $v0, $t1
    ctx->pc = 0x147160u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 9));
    // 0x147164: 0x681825  or          $v1, $v1, $t0
    ctx->pc = 0x147164u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 8));
    // 0x147168: 0xfd420000  sd          $v0, 0x0($t2)
    ctx->pc = 0x147168u;
    WRITE64(ADD32(GPR_U32(ctx, 10), 0), GPR_U64(ctx, 2));
    // 0x14716c: 0xfd430010  sd          $v1, 0x10($t2)
    ctx->pc = 0x14716cu;
    WRITE64(ADD32(GPR_U32(ctx, 10), 16), GPR_U64(ctx, 3));
    // 0x147170: 0x14e0ffe3  bnez        $a3, . + 4 + (-0x1D << 2)
    ctx->pc = 0x147170u;
    {
        const bool branch_taken_0x147170 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x147174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147170u;
            // 0x147174: 0x254a0020  addiu       $t2, $t2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147170) {
            ctx->pc = 0x147100u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_147100;
        }
    }
    ctx->pc = 0x147178u;
    // 0x147178: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x147178u;
    {
        const bool branch_taken_0x147178 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x147178) {
            ctx->pc = 0x147184u;
            goto label_147184;
        }
    }
    ctx->pc = 0x147180u;
label_147180:
    // 0x147180: 0x261105a8  addiu       $s1, $s0, 0x5A8
    ctx->pc = 0x147180u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 1448));
label_147184:
    // 0x147184: 0xc047598  jal         func_11D660
    ctx->pc = 0x147184u;
    SET_GPR_U32(ctx, 31, 0x14718Cu);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14718Cu; }
        if (ctx->pc != 0x14718Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14718Cu; }
        if (ctx->pc != 0x14718Cu) { return; }
    }
    ctx->pc = 0x14718Cu;
label_14718c:
    // 0x14718c: 0xf  sync
    ctx->pc = 0x14718cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x147190: 0x8e060828  lw          $a2, 0x828($s0)
    ctx->pc = 0x147190u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x147194: 0x24030140  addiu       $v1, $zero, 0x140
    ctx->pc = 0x147194u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x147198: 0x3c071000  lui         $a3, 0x1000
    ctx->pc = 0x147198u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)4096 << 16));
    // 0x14719c: 0x3c081000  lui         $t0, 0x1000
    ctx->pc = 0x14719cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)4096 << 16));
    // 0x1471a0: 0xc32018  mult        $a0, $a2, $v1
    ctx->pc = 0x1471a0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1471a4: 0x34e7d480  ori         $a3, $a3, 0xD480
    ctx->pc = 0x1471a4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)54400);
    // 0x1471a8: 0x264a4a00  addiu       $t2, $s2, 0x4A00
    ctx->pc = 0x1471a8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 18), 18944));
    // 0x1471ac: 0x3508d430  ori         $t0, $t0, 0xD430
    ctx->pc = 0x1471acu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)54320);
    // 0x1471b0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1471b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1471b4: 0x24090105  addiu       $t1, $zero, 0x105
    ctx->pc = 0x1471b4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 261));
    // 0x1471b8: 0x3463d420  ori         $v1, $v1, 0xD420
    ctx->pc = 0x1471b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)54304);
    // 0x1471bc: 0x913021  addu        $a2, $a0, $s1
    ctx->pc = 0x1471bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1471c0: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1471c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1471c4: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x1471c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x1471c8: 0x3484d400  ori         $a0, $a0, 0xD400
    ctx->pc = 0x1471c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)54272);
    // 0x1471cc: 0xace50000  sw          $a1, 0x0($a3)
    ctx->pc = 0x1471ccu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 5));
    // 0x1471d0: 0xad0a0000  sw          $t2, 0x0($t0)
    ctx->pc = 0x1471d0u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 10));
    // 0x1471d4: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1471d4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1471d8: 0xac890000  sw          $t1, 0x0($a0)
    ctx->pc = 0x1471d8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 9)); // MMIO: 0x10000000
    // 0x1471dc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1471DCu;
    {
        const bool branch_taken_0x1471dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1471E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1471DCu;
            // 0x1471e0: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1471dc) {
            ctx->pc = 0x1471F8u;
            goto label_1471f8;
        }
    }
    ctx->pc = 0x1471E4u;
    // 0x1471e4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1471e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1471e8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1471e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1471ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1471ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1471f0: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x1471F0u;
    ctx->pc = 0x1471F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1471F0u;
            // 0x1471f4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1471F8u;
label_1471f8:
    // 0x1471f8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1471f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1471fc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1471fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x147200: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x147200u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x147204: 0x3e00008  jr          $ra
    ctx->pc = 0x147204u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147204u;
            // 0x147208: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147100u: goto label_147100;
            case 0x147180u: goto label_147180;
            case 0x147184u: goto label_147184;
            case 0x14718Cu: goto label_14718c;
            case 0x1471F8u: goto label_1471f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14720Cu;
    // 0x14720c: 0x0  nop
    ctx->pc = 0x14720cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
