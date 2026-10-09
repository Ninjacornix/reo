#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6220
// Address: 0x1d6220 - 0x1d6370
void sub_001D6220_0x1d6220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6220_0x1d6220");
#endif

    switch (ctx->pc) {
        case 0x1d62b0u: goto label_1d62b0;
        case 0x1d62f8u: goto label_1d62f8;
        case 0x1d6310u: goto label_1d6310;
        default: break;
    }

    ctx->pc = 0x1d6220u;

    // 0x1d6220: 0x24020038  addiu       $v0, $zero, 0x38
    ctx->pc = 0x1d6220u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
    // 0x1d6224: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d6224u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d6228: 0x822018  mult        $a0, $a0, $v0
    ctx->pc = 0x1d6228u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1d622c: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1d622cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1d6230: 0x8c6a2844  lw          $t2, 0x2844($v1)
    ctx->pc = 0x1d6230u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10308)));
    // 0x1d6234: 0xffb70070  sd          $s7, 0x70($sp)
    ctx->pc = 0x1d6234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
    // 0x1d6238: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x1d6238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x1d623c: 0x30b700ff  andi        $s7, $a1, 0xFF
    ctx->pc = 0x1d623cu;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d6240: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x1d6240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x1d6244: 0x30d600ff  andi        $s6, $a2, 0xFF
    ctx->pc = 0x1d6244u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1d6248: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x1d6248u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x1d624c: 0x120a82d  daddu       $s5, $t1, $zero
    ctx->pc = 0x1d624cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6250: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x1d6250u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x1d6254: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x1d6254u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6258: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1d6258u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1d625c: 0x1449821  addu        $s3, $t2, $a0
    ctx->pc = 0x1d625cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 4)));
    // 0x1d6260: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1d6260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1d6264: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x1d6264u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6268: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1d6268u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1d626c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1d626cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1d6270: 0x8e630004  lw          $v1, 0x4($s3)
    ctx->pc = 0x1d6270u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x1d6274: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D6274u;
    {
        const bool branch_taken_0x1d6274 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6274u;
            // 0x1d6278: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6274) {
            ctx->pc = 0x1D6290u;
            goto label_1d6290;
        }
    }
    ctx->pc = 0x1D627Cu;
    // 0x1d627c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d627cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d6280: 0x10620017  beq         $v1, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1D6280u;
    {
        const bool branch_taken_0x1d6280 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D6284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6280u;
            // 0x1d6284: 0xdfbf0080  ld          $ra, 0x80($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6280) {
            ctx->pc = 0x1D62E0u;
            goto label_1d62e0;
        }
    }
    ctx->pc = 0x1D6288u;
    // 0x1d6288: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1D6288u;
    {
        const bool branch_taken_0x1d6288 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D628Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6288u;
            // 0x1d628c: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6288) {
            ctx->pc = 0x1D6344u;
            goto label_1d6344;
        }
    }
    ctx->pc = 0x1D6290u;
label_1d6290:
    // 0x1d6290: 0x1a800029  blez        $s4, . + 4 + (0x29 << 2)
    ctx->pc = 0x1D6290u;
    {
        const bool branch_taken_0x1d6290 = (GPR_S64(ctx, 20) <= 0);
        ctx->pc = 0x1D6294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6290u;
            // 0x1d6294: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6290) {
            ctx->pc = 0x1D6338u;
            goto label_1d6338;
        }
    }
    ctx->pc = 0x1D6298u;
    // 0x1d6298: 0x96420000  lhu         $v0, 0x0($s2)
    ctx->pc = 0x1d6298u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1d629c: 0x10400026  beqz        $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x1D629Cu;
    {
        const bool branch_taken_0x1d629c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D62A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D629Cu;
            // 0x1d62a0: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d629c) {
            ctx->pc = 0x1D6338u;
            goto label_1d6338;
        }
    }
    ctx->pc = 0x1D62A4u;
    // 0x1d62a4: 0x2121021  addu        $v0, $s0, $s2
    ctx->pc = 0x1d62a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x1d62a8: 0x2152021  addu        $a0, $s0, $s5
    ctx->pc = 0x1d62a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 21)));
    // 0x1d62ac: 0x0  nop
    ctx->pc = 0x1d62acu;
    // NOP
label_1d62b0:
    // 0x1d62b0: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x1d62b0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d62b4: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1d62b4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1d62b8: 0x234102a  slt         $v0, $s1, $s4
    ctx->pc = 0x1d62b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x1d62bc: 0x1040001e  beqz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1D62BCu;
    {
        const bool branch_taken_0x1d62bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D62C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D62BCu;
            // 0x1d62c0: 0xa4830000  sh          $v1, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d62bc) {
            ctx->pc = 0x1D6338u;
            goto label_1d6338;
        }
    }
    ctx->pc = 0x1D62C4u;
    // 0x1d62c4: 0x118040  sll         $s0, $s1, 1
    ctx->pc = 0x1d62c4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1d62c8: 0x2121021  addu        $v0, $s0, $s2
    ctx->pc = 0x1d62c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x1d62cc: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x1d62ccu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d62d0: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1D62D0u;
    {
        const bool branch_taken_0x1d62d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D62D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D62D0u;
            // 0x1d62d4: 0x2152021  addu        $a0, $s0, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d62d0) {
            ctx->pc = 0x1D62B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d62b0;
        }
    }
    ctx->pc = 0x1D62D8u;
    // 0x1d62d8: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1D62D8u;
    {
        const bool branch_taken_0x1d62d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D62DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D62D8u;
            // 0x1d62dc: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d62d8) {
            ctx->pc = 0x1D633Cu;
            goto label_1d633c;
        }
    }
    ctx->pc = 0x1D62E0u;
label_1d62e0:
    // 0x1d62e0: 0x1a800015  blez        $s4, . + 4 + (0x15 << 2)
    ctx->pc = 0x1D62E0u;
    {
        const bool branch_taken_0x1d62e0 = (GPR_S64(ctx, 20) <= 0);
        ctx->pc = 0x1D62E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D62E0u;
            // 0x1d62e4: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d62e0) {
            ctx->pc = 0x1D6338u;
            goto label_1d6338;
        }
    }
    ctx->pc = 0x1D62E8u;
    // 0x1d62e8: 0x96420000  lhu         $v0, 0x0($s2)
    ctx->pc = 0x1d62e8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1d62ec: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D62ECu;
    {
        const bool branch_taken_0x1d62ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D62F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D62ECu;
            // 0x1d62f0: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d62ec) {
            ctx->pc = 0x1D6338u;
            goto label_1d6338;
        }
    }
    ctx->pc = 0x1D62F4u;
    // 0x1d62f4: 0x2121021  addu        $v0, $s0, $s2
    ctx->pc = 0x1d62f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
label_1d62f8:
    // 0x1d62f8: 0x8e640008  lw          $a0, 0x8($s3)
    ctx->pc = 0x1d62f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1d62fc: 0x94470000  lhu         $a3, 0x0($v0)
    ctx->pc = 0x1d62fcu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d6300: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x1d6300u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6304: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x1d6304u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6308: 0xc0758dc  jal         func_1D6370
    ctx->pc = 0x1D6308u;
    SET_GPR_U32(ctx, 31, 0x1D6310u);
    ctx->pc = 0x1D630Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6308u;
            // 0x1d630c: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6370u;
    if (runtime->hasFunction(0x1D6370u)) {
        auto targetFn = runtime->lookupFunction(0x1D6370u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6310u; }
        if (ctx->pc != 0x1D6310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6370_0x1d6370(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6310u; }
        if (ctx->pc != 0x1D6310u) { return; }
    }
    ctx->pc = 0x1D6310u;
label_1d6310:
    // 0x1d6310: 0x2151821  addu        $v1, $s0, $s5
    ctx->pc = 0x1d6310u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 21)));
    // 0x1d6314: 0x234202a  slt         $a0, $s1, $s4
    ctx->pc = 0x1d6314u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x1d6318: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D6318u;
    {
        const bool branch_taken_0x1d6318 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D631Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6318u;
            // 0x1d631c: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6318) {
            ctx->pc = 0x1D6338u;
            goto label_1d6338;
        }
    }
    ctx->pc = 0x1D6320u;
    // 0x1d6320: 0x111040  sll         $v0, $s1, 1
    ctx->pc = 0x1d6320u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1d6324: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1d6324u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6328: 0x2121821  addu        $v1, $s0, $s2
    ctx->pc = 0x1d6328u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x1d632c: 0x94620000  lhu         $v0, 0x0($v1)
    ctx->pc = 0x1d632cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d6330: 0x1440fff1  bnez        $v0, . + 4 + (-0xF << 2)
    ctx->pc = 0x1D6330u;
    {
        const bool branch_taken_0x1d6330 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D6334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6330u;
            // 0x1d6334: 0x2121021  addu        $v0, $s0, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6330) {
            ctx->pc = 0x1D62F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d62f8;
        }
    }
    ctx->pc = 0x1D6338u;
label_1d6338:
    // 0x1d6338: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d6338u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1d633c:
    // 0x1d633c: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1d633cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1d6340: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1d6340u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1d6344:
    // 0x1d6344: 0xdfb70070  ld          $s7, 0x70($sp)
    ctx->pc = 0x1d6344u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1d6348: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x1d6348u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d634c: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x1d634cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d6350: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x1d6350u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d6354: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x1d6354u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d6358: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1d6358u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d635c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1d635cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d6360: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1d6360u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6364: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6364u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6364u;
            // 0x1d6368: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6290u: goto label_1d6290;
            case 0x1D62B0u: goto label_1d62b0;
            case 0x1D62E0u: goto label_1d62e0;
            case 0x1D62F8u: goto label_1d62f8;
            case 0x1D6310u: goto label_1d6310;
            case 0x1D6338u: goto label_1d6338;
            case 0x1D633Cu: goto label_1d633c;
            case 0x1D6344u: goto label_1d6344;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D636Cu;
    // 0x1d636c: 0x0  nop
    ctx->pc = 0x1d636cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
