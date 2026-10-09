#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133240
// Address: 0x133240 - 0x133428
void sub_00133240_0x133240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133240_0x133240");
#endif

    switch (ctx->pc) {
        case 0x1332ecu: goto label_1332ec;
        case 0x133318u: goto label_133318;
        case 0x133330u: goto label_133330;
        case 0x133348u: goto label_133348;
        case 0x133360u: goto label_133360;
        case 0x13337cu: goto label_13337c;
        case 0x1333a8u: goto label_1333a8;
        case 0x1333bcu: goto label_1333bc;
        case 0x1333d4u: goto label_1333d4;
        case 0x1333ecu: goto label_1333ec;
        default: break;
    }

    ctx->pc = 0x133240u;

    // 0x133240: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x133240u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133244: 0x28e30002  slti        $v1, $a3, 0x2
    ctx->pc = 0x133244u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x133248: 0x1460000b  bnez        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x133248u;
    {
        const bool branch_taken_0x133248 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13324Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133248u;
            // 0x13324c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133248) {
            ctx->pc = 0x133278u;
            goto label_133278;
        }
    }
    ctx->pc = 0x133250u;
    // 0x133250: 0x94830000  lhu         $v1, 0x0($a0)
    ctx->pc = 0x133250u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x133254: 0x34058001  ori         $a1, $zero, 0x8001
    ctx->pc = 0x133254u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x133258: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x133258u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x13325c: 0x31a02  srl         $v1, $v1, 8
    ctx->pc = 0x13325cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0x133260: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x133260u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x133264: 0x3063ffff  andi        $v1, $v1, 0xFFFF
    ctx->pc = 0x133264u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x133268: 0x14650003  bne         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x133268u;
    {
        const bool branch_taken_0x133268 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x133268) {
            ctx->pc = 0x133278u;
            goto label_133278;
        }
    }
    ctx->pc = 0x133270u;
    // 0x133270: 0xacc70000  sw          $a3, 0x0($a2)
    ctx->pc = 0x133270u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 7));
    // 0x133274: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x133274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_133278:
    // 0x133278: 0x3e00008  jr          $ra
    ctx->pc = 0x133278u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133278u: goto label_133278;
            case 0x1332ECu: goto label_1332ec;
            case 0x1332F4u: goto label_1332f4;
            case 0x133318u: goto label_133318;
            case 0x133330u: goto label_133330;
            case 0x133348u: goto label_133348;
            case 0x133360u: goto label_133360;
            case 0x13337Cu: goto label_13337c;
            case 0x133384u: goto label_133384;
            case 0x1333A8u: goto label_1333a8;
            case 0x1333BCu: goto label_1333bc;
            case 0x1333D4u: goto label_1333d4;
            case 0x1333ECu: goto label_1333ec;
            case 0x1333F8u: goto label_1333f8;
            case 0x133400u: goto label_133400;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133280u;
    // 0x133280: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x133280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x133284: 0x24c3001f  addiu       $v1, $a2, 0x1F
    ctx->pc = 0x133284u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 31));
    // 0x133288: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x133288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x13328c: 0x28c20000  slti        $v0, $a2, 0x0
    ctx->pc = 0x13328cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x133290: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x133290u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x133294: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x133294u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
    // 0x133298: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x133298u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x13329c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x13329cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1332a0: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x1332a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x1332a4: 0x218c0  sll         $v1, $v0, 3
    ctx->pc = 0x1332a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1332a8: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x1332a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x1332ac: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1332acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1332b0: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x1332b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x1332b4: 0x63143  sra         $a2, $a2, 5
    ctx->pc = 0x1332b4u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 5));
    // 0x1332b8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1332b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1332bc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1332bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1332c0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1332c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1332c4: 0x38040  sll         $s0, $v1, 1
    ctx->pc = 0x1332c4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1332c8: 0x8c940014  lw          $s4, 0x14($a0)
    ctx->pc = 0x1332c8u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1332cc: 0x1280004c  beqz        $s4, . + 4 + (0x4C << 2)
    ctx->pc = 0x1332CCu;
    {
        const bool branch_taken_0x1332cc = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x1332D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1332CCu;
            // 0x1332d0: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1332cc) {
            ctx->pc = 0x133400u;
            goto label_133400;
        }
    }
    ctx->pc = 0x1332D4u;
    // 0x1332d4: 0xd09818  mult        $s3, $a2, $s0
    ctx->pc = 0x1332d4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 19, (int32_t)result); }
    // 0x1332d8: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x1332d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1332dc: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x1332dcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1332e0: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x1332e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1332e4: 0x40f809  jalr        $v0
    ctx->pc = 0x1332E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1332ECu);
        ctx->pc = 0x1332E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1332E4u;
            // 0x1332e8: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1332ECu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133278u: goto label_133278;
            case 0x1332ECu: goto label_1332ec;
            case 0x1332F4u: goto label_1332f4;
            case 0x133318u: goto label_133318;
            case 0x133330u: goto label_133330;
            case 0x133348u: goto label_133348;
            case 0x133360u: goto label_133360;
            case 0x13337Cu: goto label_13337c;
            case 0x133384u: goto label_133384;
            case 0x1333A8u: goto label_1333a8;
            case 0x1333BCu: goto label_1333bc;
            case 0x1333D4u: goto label_1333d4;
            case 0x1333ECu: goto label_1333ec;
            case 0x1333F8u: goto label_1333f8;
            case 0x133400u: goto label_133400;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1332ECu; }
            if (ctx->pc != 0x1332ECu) { return; }
        }
        }
    }
    ctx->pc = 0x1332ECu;
label_1332ec:
    // 0x1332ec: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1332ECu;
    {
        const bool branch_taken_0x1332ec = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1332ec) {
            ctx->pc = 0x1332F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1332ECu;
            // 0x1332f0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1332F4u;
            goto label_1332f4;
        }
    }
    ctx->pc = 0x1332F4u;
label_1332f4:
    // 0x1332f4: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x1332f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1332f8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1332f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1332fc: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x1332fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133300: 0x50001a  div         $zero, $v0, $s0
    ctx->pc = 0x133300u;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x133304: 0x1012  mflo        $v0
    ctx->pc = 0x133304u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x133308: 0x50a818  mult        $s5, $v0, $s0
    ctx->pc = 0x133308u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 21, (int32_t)result); }
    // 0x13330c: 0x2a0882d  daddu       $s1, $s5, $zero
    ctx->pc = 0x13330cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133310: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x133310u;
    SET_GPR_U32(ctx, 31, 0x133318u);
    ctx->pc = 0x133314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133310u;
            // 0x133314: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133318u; }
        if (ctx->pc != 0x133318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133318u; }
        if (ctx->pc != 0x133318u) { return; }
    }
    ctx->pc = 0x133318u;
label_133318:
    // 0x133318: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x133318u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13331c: 0x27b20010  addiu       $s2, $sp, 0x10
    ctx->pc = 0x13331cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x133320: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x133320u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133324: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x133324u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133328: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x133328u;
    SET_GPR_U32(ctx, 31, 0x133330u);
    ctx->pc = 0x13332Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133328u;
            // 0x13332c: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133330u; }
        if (ctx->pc != 0x133330u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133330u; }
        if (ctx->pc != 0x133330u) { return; }
    }
    ctx->pc = 0x133330u;
label_133330:
    // 0x133330: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x133330u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x133334: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x133334u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133338: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x133338u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13333c: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x13333cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x133340: 0x40f809  jalr        $v0
    ctx->pc = 0x133340u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133348u);
        ctx->pc = 0x133344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133340u;
            // 0x133344: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133348u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133278u: goto label_133278;
            case 0x1332ECu: goto label_1332ec;
            case 0x1332F4u: goto label_1332f4;
            case 0x133318u: goto label_133318;
            case 0x133330u: goto label_133330;
            case 0x133348u: goto label_133348;
            case 0x133360u: goto label_133360;
            case 0x13337Cu: goto label_13337c;
            case 0x133384u: goto label_133384;
            case 0x1333A8u: goto label_1333a8;
            case 0x1333BCu: goto label_1333bc;
            case 0x1333D4u: goto label_1333d4;
            case 0x1333ECu: goto label_1333ec;
            case 0x1333F8u: goto label_1333f8;
            case 0x133400u: goto label_133400;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133348u; }
            if (ctx->pc != 0x133348u) { return; }
        }
        }
    }
    ctx->pc = 0x133348u;
label_133348:
    // 0x133348: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x133348u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x13334c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x13334cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133350: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x133350u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133354: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x133354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x133358: 0x40f809  jalr        $v0
    ctx->pc = 0x133358u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133360u);
        ctx->pc = 0x13335Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133358u;
            // 0x13335c: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133360u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133278u: goto label_133278;
            case 0x1332ECu: goto label_1332ec;
            case 0x1332F4u: goto label_1332f4;
            case 0x133318u: goto label_133318;
            case 0x133330u: goto label_133330;
            case 0x133348u: goto label_133348;
            case 0x133360u: goto label_133360;
            case 0x13337Cu: goto label_13337c;
            case 0x133384u: goto label_133384;
            case 0x1333A8u: goto label_1333a8;
            case 0x1333BCu: goto label_1333bc;
            case 0x1333D4u: goto label_1333d4;
            case 0x1333ECu: goto label_1333ec;
            case 0x1333F8u: goto label_1333f8;
            case 0x133400u: goto label_133400;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133360u; }
            if (ctx->pc != 0x133360u) { return; }
        }
        }
    }
    ctx->pc = 0x133360u;
label_133360:
    // 0x133360: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x133360u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x133364: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x133364u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133368: 0x2713023  subu        $a2, $s3, $s1
    ctx->pc = 0x133368u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
    // 0x13336c: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x13336cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x133370: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x133370u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133374: 0x40f809  jalr        $v0
    ctx->pc = 0x133374u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13337Cu);
        ctx->pc = 0x133378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133374u;
            // 0x133378: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13337Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133278u: goto label_133278;
            case 0x1332ECu: goto label_1332ec;
            case 0x1332F4u: goto label_1332f4;
            case 0x133318u: goto label_133318;
            case 0x133330u: goto label_133330;
            case 0x133348u: goto label_133348;
            case 0x133360u: goto label_133360;
            case 0x13337Cu: goto label_13337c;
            case 0x133384u: goto label_133384;
            case 0x1333A8u: goto label_1333a8;
            case 0x1333BCu: goto label_1333bc;
            case 0x1333D4u: goto label_1333d4;
            case 0x1333ECu: goto label_1333ec;
            case 0x1333F8u: goto label_1333f8;
            case 0x133400u: goto label_133400;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13337Cu; }
            if (ctx->pc != 0x13337Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13337Cu;
label_13337c:
    // 0x13337c: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13337Cu;
    {
        const bool branch_taken_0x13337c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x13337c) {
            ctx->pc = 0x133380u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13337Cu;
            // 0x133380: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x133384u;
            goto label_133384;
        }
    }
    ctx->pc = 0x133384u;
label_133384:
    // 0x133384: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x133384u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x133388: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x133388u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13338c: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x13338cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133390: 0x50001a  div         $zero, $v0, $s0
    ctx->pc = 0x133390u;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x133394: 0x1012  mflo        $v0
    ctx->pc = 0x133394u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x133398: 0x50a818  mult        $s5, $v0, $s0
    ctx->pc = 0x133398u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 21, (int32_t)result); }
    // 0x13339c: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x13339cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1333a0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1333A0u;
    SET_GPR_U32(ctx, 31, 0x1333A8u);
    ctx->pc = 0x1333A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1333A0u;
            // 0x1333a4: 0x2358821  addu        $s1, $s1, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1333A8u; }
        if (ctx->pc != 0x1333A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1333A8u; }
        if (ctx->pc != 0x1333A8u) { return; }
    }
    ctx->pc = 0x1333A8u;
label_1333a8:
    // 0x1333a8: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x1333a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1333ac: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1333acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1333b0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1333b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1333b4: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x1333B4u;
    SET_GPR_U32(ctx, 31, 0x1333BCu);
    ctx->pc = 0x1333B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1333B4u;
            // 0x1333b8: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1333BCu; }
        if (ctx->pc != 0x1333BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1333BCu; }
        if (ctx->pc != 0x1333BCu) { return; }
    }
    ctx->pc = 0x1333BCu;
label_1333bc:
    // 0x1333bc: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x1333bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1333c0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1333c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1333c4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1333c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1333c8: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x1333c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1333cc: 0x40f809  jalr        $v0
    ctx->pc = 0x1333CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1333D4u);
        ctx->pc = 0x1333D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1333CCu;
            // 0x1333d0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1333D4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133278u: goto label_133278;
            case 0x1332ECu: goto label_1332ec;
            case 0x1332F4u: goto label_1332f4;
            case 0x133318u: goto label_133318;
            case 0x133330u: goto label_133330;
            case 0x133348u: goto label_133348;
            case 0x133360u: goto label_133360;
            case 0x13337Cu: goto label_13337c;
            case 0x133384u: goto label_133384;
            case 0x1333A8u: goto label_1333a8;
            case 0x1333BCu: goto label_1333bc;
            case 0x1333D4u: goto label_1333d4;
            case 0x1333ECu: goto label_1333ec;
            case 0x1333F8u: goto label_1333f8;
            case 0x133400u: goto label_133400;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1333D4u; }
            if (ctx->pc != 0x1333D4u) { return; }
        }
        }
    }
    ctx->pc = 0x1333D4u;
label_1333d4:
    // 0x1333d4: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x1333d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1333d8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1333d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1333dc: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1333dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1333e0: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x1333e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1333e4: 0x40f809  jalr        $v0
    ctx->pc = 0x1333E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1333ECu);
        ctx->pc = 0x1333E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1333E4u;
            // 0x1333e8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1333ECu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133278u: goto label_133278;
            case 0x1332ECu: goto label_1332ec;
            case 0x1332F4u: goto label_1332f4;
            case 0x133318u: goto label_133318;
            case 0x133330u: goto label_133330;
            case 0x133348u: goto label_133348;
            case 0x133360u: goto label_133360;
            case 0x13337Cu: goto label_13337c;
            case 0x133384u: goto label_133384;
            case 0x1333A8u: goto label_1333a8;
            case 0x1333BCu: goto label_1333bc;
            case 0x1333D4u: goto label_1333d4;
            case 0x1333ECu: goto label_1333ec;
            case 0x1333F8u: goto label_1333f8;
            case 0x133400u: goto label_133400;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1333ECu; }
            if (ctx->pc != 0x1333ECu) { return; }
        }
        }
    }
    ctx->pc = 0x1333ECu;
label_1333ec:
    // 0x1333ec: 0x230001a  div         $zero, $s1, $s0
    ctx->pc = 0x1333ecu;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 17);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1333f0: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1333F0u;
    {
        const bool branch_taken_0x1333f0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1333f0) {
            ctx->pc = 0x1333F4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1333F0u;
            // 0x1333f4: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1333F8u;
            goto label_1333f8;
        }
    }
    ctx->pc = 0x1333F8u;
label_1333f8:
    // 0x1333f8: 0x8812  mflo        $s1
    ctx->pc = 0x1333f8u;
    SET_GPR_U64(ctx, 17, ctx->lo);
    // 0x1333fc: 0x111140  sll         $v0, $s1, 5
    ctx->pc = 0x1333fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 5));
label_133400:
    // 0x133400: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x133400u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x133404: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x133404u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x133408: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x133408u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13340c: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x13340cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x133410: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x133410u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x133414: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x133414u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x133418: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x133418u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x13341c: 0x3e00008  jr          $ra
    ctx->pc = 0x13341Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x133420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13341Cu;
            // 0x133420: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133278u: goto label_133278;
            case 0x1332ECu: goto label_1332ec;
            case 0x1332F4u: goto label_1332f4;
            case 0x133318u: goto label_133318;
            case 0x133330u: goto label_133330;
            case 0x133348u: goto label_133348;
            case 0x133360u: goto label_133360;
            case 0x13337Cu: goto label_13337c;
            case 0x133384u: goto label_133384;
            case 0x1333A8u: goto label_1333a8;
            case 0x1333BCu: goto label_1333bc;
            case 0x1333D4u: goto label_1333d4;
            case 0x1333ECu: goto label_1333ec;
            case 0x1333F8u: goto label_1333f8;
            case 0x133400u: goto label_133400;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133424u;
    // 0x133424: 0x0  nop
    ctx->pc = 0x133424u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
