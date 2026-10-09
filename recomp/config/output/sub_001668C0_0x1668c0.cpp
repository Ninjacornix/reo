#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001668C0
// Address: 0x1668c0 - 0x166988
void sub_001668C0_0x1668c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001668C0_0x1668c0");
#endif

    switch (ctx->pc) {
        case 0x166930u: goto label_166930;
        case 0x166958u: goto label_166958;
        case 0x166968u: goto label_166968;
        default: break;
    }

    ctx->pc = 0x1668c0u;

    // 0x1668c0: 0x710c0  sll         $v0, $a3, 3
    ctx->pc = 0x1668c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x1668c4: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1668c4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1668c8: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x1668c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1668cc: 0x74880  sll         $t1, $a3, 2
    ctx->pc = 0x1668ccu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1668d0: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1668d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1668d4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1668d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1668d8: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x1668d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x1668dc: 0xc93021  addu        $a2, $a2, $t1
    ctx->pc = 0x1668dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 9)));
    // 0x1668e0: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1668e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1668e4: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x1668e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1668e8: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x1668e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x1668ec: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1668ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1668f0: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1668f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1668f4: 0x828021  addu        $s0, $a0, $v0
    ctx->pc = 0x1668f4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1668f8: 0x100382d  daddu       $a3, $t0, $zero
    ctx->pc = 0x1668f8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1668fc: 0xa92821  addu        $a1, $a1, $t1
    ctx->pc = 0x1668fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
    // 0x166900: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x166900u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x166904: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x166904u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166908: 0x26110010  addiu       $s1, $s0, 0x10
    ctx->pc = 0x166908u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x16690c: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x16690Cu;
    {
        const bool branch_taken_0x16690c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x166910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16690Cu;
            // 0x166910: 0x60302d  daddu       $a2, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16690c) {
            ctx->pc = 0x166920u;
            goto label_166920;
        }
    }
    ctx->pc = 0x166914u;
    // 0x166914: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x166914u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166918: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x166918u;
    {
        const bool branch_taken_0x166918 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16691Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166918u;
            // 0x16691c: 0x24120004  addiu       $s2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166918) {
            ctx->pc = 0x166958u;
            goto label_166958;
        }
    }
    ctx->pc = 0x166920u;
label_166920:
    // 0x166920: 0x8ca50000  lw          $a1, 0x0($a1)
    ctx->pc = 0x166920u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x166924: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x166924u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x166928: 0xc059a62  jal         func_166988
    ctx->pc = 0x166928u;
    SET_GPR_U32(ctx, 31, 0x166930u);
    ctx->pc = 0x16692Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166928u;
            // 0x16692c: 0x24120005  addiu       $s2, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166988u;
    if (runtime->hasFunction(0x166988u)) {
        auto targetFn = runtime->lookupFunction(0x166988u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166930u; }
        if (ctx->pc != 0x166930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166988_0x166988(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166930u; }
        if (ctx->pc != 0x166930u) { return; }
    }
    ctx->pc = 0x166930u;
label_166930:
    // 0x166930: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x166930u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166934: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x166934u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166938: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x166938u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16693c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16693Cu;
    {
        const bool branch_taken_0x16693c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x166940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16693Cu;
            // 0x166940: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16693c) {
            ctx->pc = 0x166950u;
            goto label_166950;
        }
    }
    ctx->pc = 0x166944u;
    // 0x166944: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x166944u;
    {
        const bool branch_taken_0x166944 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x166948u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166944u;
            // 0x166948: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166944) {
            ctx->pc = 0x16696Cu;
            goto label_16696c;
        }
    }
    ctx->pc = 0x16694Cu;
    // 0x16694c: 0x0  nop
    ctx->pc = 0x16694cu;
    // NOP
label_166950:
    // 0x166950: 0xc059b9a  jal         func_166E68
    ctx->pc = 0x166950u;
    SET_GPR_U32(ctx, 31, 0x166958u);
    ctx->pc = 0x166E68u;
    if (runtime->hasFunction(0x166E68u)) {
        auto targetFn = runtime->lookupFunction(0x166E68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166958u; }
        if (ctx->pc != 0x166958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166E68_0x166e68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166958u; }
        if (ctx->pc != 0x166958u) { return; }
    }
    ctx->pc = 0x166958u;
label_166958:
    // 0x166958: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166958u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16695c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16695cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166960: 0xc059b2e  jal         func_166CB8
    ctx->pc = 0x166960u;
    SET_GPR_U32(ctx, 31, 0x166968u);
    ctx->pc = 0x166964u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166960u;
            // 0x166964: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166CB8u;
    if (runtime->hasFunction(0x166CB8u)) {
        auto targetFn = runtime->lookupFunction(0x166CB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166968u; }
        if (ctx->pc != 0x166968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166CB8_0x166cb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166968u; }
        if (ctx->pc != 0x166968u) { return; }
    }
    ctx->pc = 0x166968u;
label_166968:
    // 0x166968: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x166968u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16696c:
    // 0x16696c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x16696cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x166970: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x166970u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x166974: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x166974u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x166978: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x166978u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16697c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x16697cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x166980: 0x3e00008  jr          $ra
    ctx->pc = 0x166980u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166984u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166980u;
            // 0x166984: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166920u: goto label_166920;
            case 0x166930u: goto label_166930;
            case 0x166950u: goto label_166950;
            case 0x166958u: goto label_166958;
            case 0x166968u: goto label_166968;
            case 0x16696Cu: goto label_16696c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166988u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
