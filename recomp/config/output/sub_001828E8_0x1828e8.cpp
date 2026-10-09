#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001828E8
// Address: 0x1828e8 - 0x182a10
void sub_001828E8_0x1828e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001828E8_0x1828e8");
#endif

    switch (ctx->pc) {
        case 0x18299cu: goto label_18299c;
        default: break;
    }

    ctx->pc = 0x1828e8u;

    // 0x1828e8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1828e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1828ec: 0x240a0898  addiu       $t2, $zero, 0x898
    ctx->pc = 0x1828ecu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x1828f0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1828f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1828f4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1828f4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1828f8: 0x24a5018  mult        $t2, $s2, $t2
    ctx->pc = 0x1828f8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 10); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 10, (int32_t)result); }
    // 0x1828fc: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x1828fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x182900: 0x3c150028  lui         $s5, 0x28
    ctx->pc = 0x182900u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)40 << 16));
    // 0x182904: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x182904u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182908: 0x123840  sll         $a3, $s2, 1
    ctx->pc = 0x182908u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x18290c: 0x26a55b48  addiu       $a1, $s5, 0x5B48
    ctx->pc = 0x18290cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), 23368));
    // 0x182910: 0x28690000  slti        $t1, $v1, 0x0
    ctx->pc = 0x182910u;
    SET_GPR_U64(ctx, 9, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x182914: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x182914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x182918: 0x1451021  addu        $v0, $t2, $a1
    ctx->pc = 0x182918u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 5)));
    // 0x18291c: 0x1452821  addu        $a1, $t2, $a1
    ctx->pc = 0x18291cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 5)));
    // 0x182920: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x182920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x182924: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x182924u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182928: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x182928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x18292c: 0x340bffff  ori         $t3, $zero, 0xFFFF
    ctx->pc = 0x18292cu;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x182930: 0x1635821  addu        $t3, $t3, $v1
    ctx->pc = 0x182930u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x182934: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x182934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x182938: 0x24540804  addiu       $s4, $v0, 0x804
    ctx->pc = 0x182938u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 2052));
    // 0x18293c: 0x60402d  daddu       $t0, $v1, $zero
    ctx->pc = 0x18293cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182940: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x182940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x182944: 0xf23821  addu        $a3, $a3, $s2
    ctx->pc = 0x182944u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 18)));
    // 0x182948: 0x169400b  movn        $t0, $t3, $t1
    ctx->pc = 0x182948u;
    if (GPR_U64(ctx, 9) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 11));
    // 0x18294c: 0x28620000  slti        $v0, $v1, 0x0
    ctx->pc = 0x18294cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x182950: 0x73940  sll         $a3, $a3, 5
    ctx->pc = 0x182950u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 5));
    // 0x182954: 0x246900ff  addiu       $t1, $v1, 0xFF
    ctx->pc = 0x182954u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 3), 255));
    // 0x182958: 0x88403  sra         $s0, $t0, 16
    ctx->pc = 0x182958u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 8), 16));
    // 0x18295c: 0x122180b  movn        $v1, $t1, $v0
    ctx->pc = 0x18295cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 9));
    // 0x182960: 0xf23821  addu        $a3, $a3, $s2
    ctx->pc = 0x182960u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 18)));
    // 0x182964: 0x8e880000  lw          $t0, 0x0($s4)
    ctx->pc = 0x182964u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x182968: 0x101200  sll         $v0, $s0, 8
    ctx->pc = 0x182968u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x18296c: 0x73880  sll         $a3, $a3, 2
    ctx->pc = 0x18296cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x182970: 0x31a03  sra         $v1, $v1, 8
    ctx->pc = 0x182970u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 8));
    // 0x182974: 0x629823  subu        $s3, $v1, $v0
    ctx->pc = 0x182974u;
    SET_GPR_S32(ctx, 19, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x182978: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x182978u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x18297c: 0x2442fa18  addiu       $v0, $v0, -0x5E8
    ctx->pc = 0x18297cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294965784));
    // 0x182980: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x182980u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x182984: 0x1110000b  beq         $t0, $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x182984u;
    {
        const bool branch_taken_0x182984 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 16));
        ctx->pc = 0x182988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182984u;
            // 0x182988: 0x104880  sll         $t1, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182984) {
            ctx->pc = 0x1829B4u;
            goto label_1829b4;
        }
    }
    ctx->pc = 0x18298Cu;
    // 0x18298c: 0x1221021  addu        $v0, $t1, $v0
    ctx->pc = 0x18298cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x182990: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x182990u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x182994: 0xc061b98  jal         func_186E60
    ctx->pc = 0x182994u;
    SET_GPR_U32(ctx, 31, 0x18299Cu);
    ctx->pc = 0x182998u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182994u;
            // 0x182998: 0x8c460050  lw          $a2, 0x50($v0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 80)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186E60u;
    if (runtime->hasFunction(0x186E60u)) {
        auto targetFn = runtime->lookupFunction(0x186E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18299Cu; }
        if (ctx->pc != 0x18299Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186E60_0x186e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18299Cu; }
        if (ctx->pc != 0x18299Cu) { return; }
    }
    ctx->pc = 0x18299Cu;
label_18299c:
    // 0x18299c: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x18299cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x1829a0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1829A0u;
    {
        const bool branch_taken_0x1829a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1829A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1829A0u;
            // 0x1829a4: 0x3463006f  ori         $v1, $v1, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1829a0) {
            ctx->pc = 0x1829B0u;
            goto label_1829b0;
        }
    }
    ctx->pc = 0x1829A8u;
    // 0x1829a8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1829A8u;
    {
        const bool branch_taken_0x1829a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1829ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1829A8u;
            // 0x1829ac: 0xae230000  sw          $v1, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1829a8) {
            ctx->pc = 0x1829E8u;
            goto label_1829e8;
        }
    }
    ctx->pc = 0x1829B0u;
label_1829b0:
    // 0x1829b0: 0xae900000  sw          $s0, 0x0($s4)
    ctx->pc = 0x1829b0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 16));
label_1829b4:
    // 0x1829b4: 0x24020226  addiu       $v0, $zero, 0x226
    ctx->pc = 0x1829b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 550));
    // 0x1829b8: 0x26a35b48  addiu       $v1, $s5, 0x5B48
    ctx->pc = 0x1829b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 23368));
    // 0x1829bc: 0x2422018  mult        $a0, $s2, $v0
    ctx->pc = 0x1829bcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1829c0: 0x931021  addu        $v0, $a0, $s3
    ctx->pc = 0x1829c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 19)));
    // 0x1829c4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1829c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1829c8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1829c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1829cc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1829ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1829d0: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1829D0u;
    {
        const bool branch_taken_0x1829d0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1829d0) {
            ctx->pc = 0x1829D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1829D0u;
            // 0x1829d4: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1829E8u;
            goto label_1829e8;
        }
    }
    ctx->pc = 0x1829D8u;
    // 0x1829d8: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x1829d8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x1829dc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1829dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1829e0: 0x34639001  ori         $v1, $v1, 0x9001
    ctx->pc = 0x1829e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)36865);
    // 0x1829e4: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1829e4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_1829e8:
    // 0x1829e8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1829e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1829ec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1829ecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1829f0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1829f0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1829f4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1829f4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1829f8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1829f8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1829fc: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1829fcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x182a00: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x182a00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x182a04: 0x3e00008  jr          $ra
    ctx->pc = 0x182A04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182A04u;
            // 0x182a08: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18299Cu: goto label_18299c;
            case 0x1829B0u: goto label_1829b0;
            case 0x1829B4u: goto label_1829b4;
            case 0x1829E8u: goto label_1829e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182A0Cu;
    // 0x182a0c: 0x0  nop
    ctx->pc = 0x182a0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
