#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001201C0
// Address: 0x1201c0 - 0x1204dc
void sub_001201C0_0x1201c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001201C0_0x1201c0");
#endif

    switch (ctx->pc) {
        case 0x120210u: goto label_120210;
        case 0x120220u: goto label_120220;
        case 0x120260u: goto label_120260;
        case 0x120270u: goto label_120270;
        case 0x120288u: goto label_120288;
        case 0x1202b8u: goto label_1202b8;
        case 0x120350u: goto label_120350;
        case 0x120388u: goto label_120388;
        case 0x120414u: goto label_120414;
        case 0x120440u: goto label_120440;
        default: break;
    }

    ctx->pc = 0x1201c0u;

    // 0x1201c0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1201c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1201c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1201c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1201c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1201c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1201cc: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1201ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1201d0: 0x3c148000  lui         $s4, 0x8000
    ctx->pc = 0x1201d0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32768 << 16));
    // 0x1201d4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1201d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1201d8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1201d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1201dc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1201dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1201e0: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x1201e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x1201e4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1201e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1201e8: 0x2383c  dsll32      $a3, $v0, 0
    ctx->pc = 0x1201e8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1201ec: 0x7383f  dsra32      $a3, $a3, 0
    ctx->pc = 0x1201ecu;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 0));
    // 0x1201f0: 0x2283f  dsra32      $a1, $v0, 0
    ctx->pc = 0x1201f0u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1201f4: 0x3c037ff0  lui         $v1, 0x7FF0
    ctx->pc = 0x1201f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32752 << 16));
    // 0x1201f8: 0xa31024  and         $v0, $a1, $v1
    ctx->pc = 0x1201f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x1201fc: 0x1443000a  bne         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1201FCu;
    {
        const bool branch_taken_0x1201fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x120200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1201FCu;
            // 0x120200: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1201fc) {
            ctx->pc = 0x120228u;
            goto label_120228;
        }
    }
    ctx->pc = 0x120204u;
    // 0x120204: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x120204u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120208: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120208u;
    SET_GPR_U32(ctx, 31, 0x120210u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120210u; }
        if (ctx->pc != 0x120210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120210u; }
        if (ctx->pc != 0x120210u) { return; }
    }
    ctx->pc = 0x120210u;
label_120210:
    // 0x120210: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x120210u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120214: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x120214u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120218: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x120218u;
    SET_GPR_U32(ctx, 31, 0x120220u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120220u; }
        if (ctx->pc != 0x120220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120220u; }
        if (ctx->pc != 0x120220u) { return; }
    }
    ctx->pc = 0x120220u;
label_120220:
    // 0x120220: 0x100000a6  b           . + 4 + (0xA6 << 2)
    ctx->pc = 0x120220u;
    {
        const bool branch_taken_0x120220 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120220u;
            // 0x120224: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120220) {
            ctx->pc = 0x1204BCu;
            goto label_1204bc;
        }
    }
    ctx->pc = 0x120228u;
label_120228:
    // 0x120228: 0x1ca00013  bgtz        $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x120228u;
    {
        const bool branch_taken_0x120228 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x12022Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120228u;
            // 0x12022c: 0x58d03  sra         $s1, $a1, 20 (Delay Slot)
        SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 5), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120228) {
            ctx->pc = 0x120278u;
            goto label_120278;
        }
    }
    ctx->pc = 0x120230u;
    // 0x120230: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x120230u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x120234: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x120234u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120238: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x120238u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x12023c: 0xa31824  and         $v1, $a1, $v1
    ctx->pc = 0x12023cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x120240: 0x671825  or          $v1, $v1, $a3
    ctx->pc = 0x120240u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
    // 0x120244: 0x5060009d  beql        $v1, $zero, . + 4 + (0x9D << 2)
    ctx->pc = 0x120244u;
    {
        const bool branch_taken_0x120244 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x120244) {
            ctx->pc = 0x120248u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x120244u;
            // 0x120248: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1204BCu;
            goto label_1204bc;
        }
    }
    ctx->pc = 0x12024Cu;
    // 0x12024c: 0x4a1000a  bgez        $a1, . + 4 + (0xA << 2)
    ctx->pc = 0x12024Cu;
    {
        const bool branch_taken_0x12024c = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x12024c) {
            ctx->pc = 0x120278u;
            goto label_120278;
        }
    }
    ctx->pc = 0x120254u;
    // 0x120254: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x120254u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120258: 0xc044752  jal         func_111D48
    ctx->pc = 0x120258u;
    SET_GPR_U32(ctx, 31, 0x120260u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120260u; }
        if (ctx->pc != 0x120260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120260u; }
        if (ctx->pc != 0x120260u) { return; }
    }
    ctx->pc = 0x120260u;
label_120260:
    // 0x120260: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x120260u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120264: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x120264u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120268: 0xc04480e  jal         func_112038
    ctx->pc = 0x120268u;
    SET_GPR_U32(ctx, 31, 0x120270u);
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120270u; }
        if (ctx->pc != 0x120270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120270u; }
        if (ctx->pc != 0x120270u) { return; }
    }
    ctx->pc = 0x120270u;
label_120270:
    // 0x120270: 0x10000092  b           . + 4 + (0x92 << 2)
    ctx->pc = 0x120270u;
    {
        const bool branch_taken_0x120270 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120270u;
            // 0x120274: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120270) {
            ctx->pc = 0x1204BCu;
            goto label_1204bc;
        }
    }
    ctx->pc = 0x120278u;
label_120278:
    // 0x120278: 0x1620001d  bnez        $s1, . + 4 + (0x1D << 2)
    ctx->pc = 0x120278u;
    {
        const bool branch_taken_0x120278 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x12027Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120278u;
            // 0x12027c: 0x3c02000f  lui         $v0, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120278) {
            ctx->pc = 0x1202F0u;
            goto label_1202f0;
        }
    }
    ctx->pc = 0x120280u;
    // 0x120280: 0x14a00009  bnez        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x120280u;
    {
        const bool branch_taken_0x120280 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x120284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120280u;
            // 0x120284: 0x3c020010  lui         $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120280) {
            ctx->pc = 0x1202A8u;
            goto label_1202a8;
        }
    }
    ctx->pc = 0x120288u;
label_120288:
    // 0x120288: 0x712c2  srl         $v0, $a3, 11
    ctx->pc = 0x120288u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), 11));
    // 0x12028c: 0x73d40  sll         $a3, $a3, 21
    ctx->pc = 0x12028cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 21));
    // 0x120290: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x120290u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x120294: 0x0  nop
    ctx->pc = 0x120294u;
    // NOP
    // 0x120298: 0x0  nop
    ctx->pc = 0x120298u;
    // NOP
    // 0x12029c: 0x10a0fffa  beqz        $a1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x12029Cu;
    {
        const bool branch_taken_0x12029c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1202A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12029Cu;
            // 0x1202a0: 0x2631ffeb  addiu       $s1, $s1, -0x15 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967275));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12029c) {
            ctx->pc = 0x120288u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_120288;
        }
    }
    ctx->pc = 0x1202A4u;
    // 0x1202a4: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1202a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
label_1202a8:
    // 0x1202a8: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x1202a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x1202ac: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1202ACu;
    {
        const bool branch_taken_0x1202ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1202B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1202ACu;
            // 0x1202b0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1202ac) {
            ctx->pc = 0x1202D4u;
            goto label_1202d4;
        }
    }
    ctx->pc = 0x1202B4u;
    // 0x1202b4: 0x3c030010  lui         $v1, 0x10
    ctx->pc = 0x1202b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16 << 16));
label_1202b8:
    // 0x1202b8: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x1202b8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1202bc: 0xa31024  and         $v0, $a1, $v1
    ctx->pc = 0x1202bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x1202c0: 0x0  nop
    ctx->pc = 0x1202c0u;
    // NOP
    // 0x1202c4: 0x0  nop
    ctx->pc = 0x1202c4u;
    // NOP
    // 0x1202c8: 0x0  nop
    ctx->pc = 0x1202c8u;
    // NOP
    // 0x1202cc: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1202CCu;
    {
        const bool branch_taken_0x1202cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1202D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1202CCu;
            // 0x1202d0: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1202cc) {
            ctx->pc = 0x1202B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1202b8;
        }
    }
    ctx->pc = 0x1202D4u;
label_1202d4:
    // 0x1202d4: 0x41023  negu        $v0, $a0
    ctx->pc = 0x1202d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x1202d8: 0x2241823  subu        $v1, $s1, $a0
    ctx->pc = 0x1202d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    // 0x1202dc: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x1202dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x1202e0: 0x873804  sllv        $a3, $a3, $a0
    ctx->pc = 0x1202e0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 4) & 0x1F));
    // 0x1202e4: 0x24710001  addiu       $s1, $v1, 0x1
    ctx->pc = 0x1202e4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1202e8: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x1202e8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x1202ec: 0x3c02000f  lui         $v0, 0xF
    ctx->pc = 0x1202ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
label_1202f0:
    // 0x1202f0: 0x2631fc01  addiu       $s1, $s1, -0x3FF
    ctx->pc = 0x1202f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294966273));
    // 0x1202f4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1202f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1202f8: 0x3c040010  lui         $a0, 0x10
    ctx->pc = 0x1202f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16 << 16));
    // 0x1202fc: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x1202fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x120300: 0x32230001  andi        $v1, $s1, 0x1
    ctx->pc = 0x120300u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
    // 0x120304: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x120304u;
    {
        const bool branch_taken_0x120304 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x120308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120304u;
            // 0x120308: 0x442825  or          $a1, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120304) {
            ctx->pc = 0x120320u;
            goto label_120320;
        }
    }
    ctx->pc = 0x12030Cu;
    // 0x12030c: 0xf41024  and         $v0, $a3, $s4
    ctx->pc = 0x12030cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 20));
    // 0x120310: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x120310u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x120314: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x120314u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x120318: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x120318u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x12031c: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x12031cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_120320:
    // 0x120320: 0xf41024  and         $v0, $a3, $s4
    ctx->pc = 0x120320u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 20));
    // 0x120324: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x120324u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x120328: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x120328u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x12032c: 0x118843  sra         $s1, $s1, 1
    ctx->pc = 0x12032cu;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 1));
    // 0x120330: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x120330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x120334: 0x602d  daddu       $t4, $zero, $zero
    ctx->pc = 0x120334u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120338: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x120338u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x12033c: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x12033cu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120340: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x120340u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120344: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x120344u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120348: 0x3c090020  lui         $t1, 0x20
    ctx->pc = 0x120348u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)32 << 16));
    // 0x12034c: 0x0  nop
    ctx->pc = 0x12034cu;
    // NOP
label_120350:
    // 0x120350: 0x1691821  addu        $v1, $t3, $t1
    ctx->pc = 0x120350u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 9)));
    // 0x120354: 0xa3102a  slt         $v0, $a1, $v1
    ctx->pc = 0x120354u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x120358: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x120358u;
    {
        const bool branch_taken_0x120358 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12035Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120358u;
            // 0x12035c: 0xf41024  and         $v0, $a3, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120358) {
            ctx->pc = 0x12036Cu;
            goto label_12036c;
        }
    }
    ctx->pc = 0x120360u;
    // 0x120360: 0xa32823  subu        $a1, $a1, $v1
    ctx->pc = 0x120360u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x120364: 0x695821  addu        $t3, $v1, $t1
    ctx->pc = 0x120364u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x120368: 0x2699821  addu        $s3, $s3, $t1
    ctx->pc = 0x120368u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 9)));
label_12036c:
    // 0x12036c: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x12036cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x120370: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x120370u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x120374: 0x94842  srl         $t1, $t1, 1
    ctx->pc = 0x120374u;
    SET_GPR_S32(ctx, 9, (int32_t)SRL32(GPR_U32(ctx, 9), 1));
    // 0x120378: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x120378u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x12037c: 0x1520fff4  bnez        $t1, . + 4 + (-0xC << 2)
    ctx->pc = 0x12037Cu;
    {
        const bool branch_taken_0x12037c = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x120380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12037Cu;
            // 0x120380: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12037c) {
            ctx->pc = 0x120350u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_120350;
        }
    }
    ctx->pc = 0x120384u;
    // 0x120384: 0x3c098000  lui         $t1, 0x8000
    ctx->pc = 0x120384u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)32768 << 16));
label_120388:
    // 0x120388: 0x160182d  daddu       $v1, $t3, $zero
    ctx->pc = 0x120388u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12038c: 0x1892021  addu        $a0, $t4, $t1
    ctx->pc = 0x12038cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 9)));
    // 0x120390: 0x65102a  slt         $v0, $v1, $a1
    ctx->pc = 0x120390u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x120394: 0x945024  and         $t2, $a0, $s4
    ctx->pc = 0x120394u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 4) & GPR_U64(ctx, 20));
    // 0x120398: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x120398u;
    {
        const bool branch_taken_0x120398 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12039Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120398u;
            // 0x12039c: 0xe4402b  sltu        $t0, $a3, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 8, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120398) {
            ctx->pc = 0x1203B0u;
            goto label_1203b0;
        }
    }
    ctx->pc = 0x1203A0u;
    // 0x1203a0: 0x1465000d  bne         $v1, $a1, . + 4 + (0xD << 2)
    ctx->pc = 0x1203A0u;
    {
        const bool branch_taken_0x1203a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1203A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1203A0u;
            // 0x1203a4: 0xf41024  and         $v0, $a3, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1203a0) {
            ctx->pc = 0x1203D8u;
            goto label_1203d8;
        }
    }
    ctx->pc = 0x1203A8u;
    // 0x1203a8: 0x5500000c  bnel        $t0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x1203A8u;
    {
        const bool branch_taken_0x1203a8 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        if (branch_taken_0x1203a8) {
            ctx->pc = 0x1203ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1203A8u;
            // 0x1203ac: 0x73840  sll         $a3, $a3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1203DCu;
            goto label_1203dc;
        }
    }
    ctx->pc = 0x1203B0u;
label_1203b0:
    // 0x1203b0: 0x896021  addu        $t4, $a0, $t1
    ctx->pc = 0x1203b0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1203b4: 0x15540003  bne         $t2, $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x1203B4u;
    {
        const bool branch_taken_0x1203b4 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 20));
        ctx->pc = 0x1203B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1203B4u;
            // 0x1203b8: 0x1943024  and         $a2, $t4, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 12) & GPR_U64(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1203b4) {
            ctx->pc = 0x1203C4u;
            goto label_1203c4;
        }
    }
    ctx->pc = 0x1203BCu;
    // 0x1203bc: 0x25620001  addiu       $v0, $t3, 0x1
    ctx->pc = 0x1203bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x1203c0: 0x46580a  movz        $t3, $v0, $a2
    ctx->pc = 0x1203c0u;
    if (GPR_U64(ctx, 6) == 0) SET_GPR_VEC(ctx, 11, GPR_VEC(ctx, 2));
label_1203c4:
    // 0x1203c4: 0xa32823  subu        $a1, $a1, $v1
    ctx->pc = 0x1203c4u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1203c8: 0xe43823  subu        $a3, $a3, $a0
    ctx->pc = 0x1203c8u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x1203cc: 0x2499021  addu        $s2, $s2, $t1
    ctx->pc = 0x1203ccu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 9)));
    // 0x1203d0: 0xa82823  subu        $a1, $a1, $t0
    ctx->pc = 0x1203d0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
    // 0x1203d4: 0xf41024  and         $v0, $a3, $s4
    ctx->pc = 0x1203d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 20));
label_1203d8:
    // 0x1203d8: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x1203d8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
label_1203dc:
    // 0x1203dc: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x1203dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x1203e0: 0x94842  srl         $t1, $t1, 1
    ctx->pc = 0x1203e0u;
    SET_GPR_S32(ctx, 9, (int32_t)SRL32(GPR_U32(ctx, 9), 1));
    // 0x1203e4: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1203e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1203e8: 0x1520ffe7  bnez        $t1, . + 4 + (-0x19 << 2)
    ctx->pc = 0x1203E8u;
    {
        const bool branch_taken_0x1203e8 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x1203ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1203E8u;
            // 0x1203ec: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1203e8) {
            ctx->pc = 0x120388u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_120388;
        }
    }
    ctx->pc = 0x1203F0u;
    // 0x1203f0: 0xa71025  or          $v0, $a1, $a3
    ctx->pc = 0x1203f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1203f4: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1203F4u;
    {
        const bool branch_taken_0x1203f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1203F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1203F4u;
            // 0x1203f8: 0x123842  srl         $a3, $s2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1203f4) {
            ctx->pc = 0x120468u;
            goto label_120468;
        }
    }
    ctx->pc = 0x1203FCu;
    // 0x1203fc: 0x3410ffc0  ori         $s0, $zero, 0xFFC0
    ctx->pc = 0x1203fcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x120400: 0x1083bc  dsll32      $s0, $s0, 14
    ctx->pc = 0x120400u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 14));
    // 0x120404: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x120404u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120408: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x120408u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12040c: 0xc0448a6  jal         func_112298
    ctx->pc = 0x12040Cu;
    SET_GPR_U32(ctx, 31, 0x120414u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120414u; }
        if (ctx->pc != 0x120414u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120414u; }
        if (ctx->pc != 0x120414u) { return; }
    }
    ctx->pc = 0x120414u;
label_120414:
    // 0x120414: 0x4400013  bltz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x120414u;
    {
        const bool branch_taken_0x120414 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x120418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120414u;
            // 0x120418: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120414) {
            ctx->pc = 0x120464u;
            goto label_120464;
        }
    }
    ctx->pc = 0x12041Cu;
    // 0x12041c: 0x16420004  bne         $s2, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12041Cu;
    {
        const bool branch_taken_0x12041c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x12041c) {
            ctx->pc = 0x120430u;
            goto label_120430;
        }
    }
    ctx->pc = 0x120424u;
    // 0x120424: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x120424u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120428: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x120428u;
    {
        const bool branch_taken_0x120428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12042Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120428u;
            // 0x12042c: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120428) {
            ctx->pc = 0x120464u;
            goto label_120464;
        }
    }
    ctx->pc = 0x120430u;
label_120430:
    // 0x120430: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x120430u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120434: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x120434u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120438: 0xc0448a6  jal         func_112298
    ctx->pc = 0x120438u;
    SET_GPR_U32(ctx, 31, 0x120440u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120440u; }
        if (ctx->pc != 0x120440u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120440u; }
        if (ctx->pc != 0x120440u) { return; }
    }
    ctx->pc = 0x120440u;
label_120440:
    // 0x120440: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x120440u;
    {
        const bool branch_taken_0x120440 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x120444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120440u;
            // 0x120444: 0x32420001  andi        $v0, $s2, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120440) {
            ctx->pc = 0x120460u;
            goto label_120460;
        }
    }
    ctx->pc = 0x120448u;
    // 0x120448: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x120448u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x12044c: 0x26630001  addiu       $v1, $s3, 0x1
    ctx->pc = 0x12044cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x120450: 0x2421026  xor         $v0, $s2, $v0
    ctx->pc = 0x120450u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) ^ GPR_U64(ctx, 2));
    // 0x120454: 0x26520002  addiu       $s2, $s2, 0x2
    ctx->pc = 0x120454u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
    // 0x120458: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x120458u;
    {
        const bool branch_taken_0x120458 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12045Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120458u;
            // 0x12045c: 0x62980a  movz        $s3, $v1, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120458) {
            ctx->pc = 0x120464u;
            goto label_120464;
        }
    }
    ctx->pc = 0x120460u;
label_120460:
    // 0x120460: 0x2429021  addu        $s2, $s2, $v0
    ctx->pc = 0x120460u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
label_120464:
    // 0x120464: 0x123842  srl         $a3, $s2, 1
    ctx->pc = 0x120464u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 18), 1));
label_120468:
    // 0x120468: 0x131043  sra         $v0, $s3, 1
    ctx->pc = 0x120468u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 19), 1));
    // 0x12046c: 0x3c053fe0  lui         $a1, 0x3FE0
    ctx->pc = 0x12046cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16352 << 16));
    // 0x120470: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x120470u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x120474: 0xf41025  or          $v0, $a3, $s4
    ctx->pc = 0x120474u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) | GPR_U64(ctx, 20));
    // 0x120478: 0x32640001  andi        $a0, $s3, 0x1
    ctx->pc = 0x120478u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)1);
    // 0x12047c: 0x111d00  sll         $v1, $s1, 20
    ctx->pc = 0x12047cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 20));
    // 0x120480: 0x44380b  movn        $a3, $v0, $a0
    ctx->pc = 0x120480u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 2));
    // 0x120484: 0xa32821  addu        $a1, $a1, $v1
    ctx->pc = 0x120484u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x120488: 0x5203c  dsll32      $a0, $a1, 0
    ctx->pc = 0x120488u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) << (32 + 0));
    // 0x12048c: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x12048cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x120490: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x120490u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x120494: 0x2a2a824  and         $s5, $s5, $v0
    ctx->pc = 0x120494u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) & GPR_U64(ctx, 2));
    // 0x120498: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x120498u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x12049c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x12049cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1204a0: 0x7183c  dsll32      $v1, $a3, 0
    ctx->pc = 0x1204a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 0));
    // 0x1204a4: 0x2a4a825  or          $s5, $s5, $a0
    ctx->pc = 0x1204a4u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) | GPR_U64(ctx, 4));
    // 0x1204a8: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x1204a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1204ac: 0x2a2a824  and         $s5, $s5, $v0
    ctx->pc = 0x1204acu;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) & GPR_U64(ctx, 2));
    // 0x1204b0: 0x2a38025  or          $s0, $s5, $v1
    ctx->pc = 0x1204b0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 21) | GPR_U64(ctx, 3));
    // 0x1204b4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1204b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1204b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1204b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1204bc:
    // 0x1204bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1204bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1204c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1204c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1204c4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1204c4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1204c8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1204c8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1204cc: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1204ccu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1204d0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1204d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1204d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1204D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1204D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1204D4u;
            // 0x1204d8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x120210u: goto label_120210;
            case 0x120220u: goto label_120220;
            case 0x120228u: goto label_120228;
            case 0x120260u: goto label_120260;
            case 0x120270u: goto label_120270;
            case 0x120278u: goto label_120278;
            case 0x120288u: goto label_120288;
            case 0x1202A8u: goto label_1202a8;
            case 0x1202B8u: goto label_1202b8;
            case 0x1202D4u: goto label_1202d4;
            case 0x1202F0u: goto label_1202f0;
            case 0x120320u: goto label_120320;
            case 0x120350u: goto label_120350;
            case 0x12036Cu: goto label_12036c;
            case 0x120388u: goto label_120388;
            case 0x1203B0u: goto label_1203b0;
            case 0x1203C4u: goto label_1203c4;
            case 0x1203D8u: goto label_1203d8;
            case 0x1203DCu: goto label_1203dc;
            case 0x120414u: goto label_120414;
            case 0x120430u: goto label_120430;
            case 0x120440u: goto label_120440;
            case 0x120460u: goto label_120460;
            case 0x120464u: goto label_120464;
            case 0x120468u: goto label_120468;
            case 0x1204BCu: goto label_1204bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1204DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
